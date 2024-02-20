#include <iostream>
#include <vector>
#include <algorithm>

const int ORDER = 3; // Order of the B+ tree

struct BPlusTreeNode {
    std::vector<int> keys;
    std::vector<BPlusTreeNode*> children;
    BPlusTreeNode* next; // Pointer to the next leaf node (used for range queries)

    BPlusTreeNode() : next(nullptr) {}
};

class BPlusTree {
private:
    BPlusTreeNode* root;

public:
    BPlusTree() : root(nullptr) {}

    void insert(int key) {
        if (root == nullptr) {
            root = new BPlusTreeNode();
        }
        if (root->keys.size() == ORDER - 1) {
            BPlusTreeNode* newRoot = new BPlusTreeNode();
            newRoot->children.push_back(root);
            splitChild(newRoot, 0);
            root = newRoot;
        }
        insertNonFull(root, key);
    }

    bool search(int key) {
        return searchKey(root, key);
    }

    std::vector<int> rangeQuery(int min_key, int max_key) {
        std::vector<int> result;
        BPlusTreeNode* current = findLeafNode(root, min_key);

        while (current != nullptr) {
            for (int k : current->keys) {
                if (k >= min_key && k <= max_key) {
                    result.push_back(k);
                }
                if (k > max_key) {
                    return result;
                }
            }
            current = current->next;
        }

        return result;
    }

    void print() {
        printTree(root);
    }

private:
    void insertNonFull(BPlusTreeNode* node, int key) {
        int i = node->keys.size() - 1;

        if (node->keys.empty() || key > node->keys.back()) {
            node->keys.push_back(key);
        } else {
            while (i >= 0 && key < node->keys[i]) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
        }

        if (!node->children.empty()) {
            while (i >= 0 && key < node->keys[i]) {
                i--;
            }
            i++;
            if (node->children[i]->keys.size() == ORDER) {
                splitChild(node, i);
                if (key > node->keys[i]) {
                    i++;
                }
            }
            insertNonFull(node->children[i], key);
        }
    }

    void splitChild(BPlusTreeNode* parent, int childIndex) {
        BPlusTreeNode* child = parent->children[childIndex];
        BPlusTreeNode* newChild = new BPlusTreeNode();

        parent->keys.insert(parent->keys.begin() + childIndex, child->keys[ORDER / 2]);
        parent->children.insert(parent->children.begin() + childIndex + 1, newChild);

        newChild->keys.assign(child->keys.begin() + (ORDER / 2), child->keys.end());
        child->keys.erase(child->keys.begin() + (ORDER / 2), child->keys.end());

        if (!child->children.empty()) {
            newChild->children.assign(child->children.begin() + (ORDER / 2), child->children.end());
            child->children.erase(child->children.begin() + (ORDER / 2), child->children.end());
        }

        if (child->next) {
            newChild->next = child->next;
            child->next = newChild;
        }
    }

    bool searchKey(BPlusTreeNode* node, int key) {
        if (!node)
            return false;

        if (std::binary_search(node->keys.begin(), node->keys.end(), key)) {
            return true;
        }

        if (node->children.empty()) {
            return false;
        }

        int i = 0;
        while (i < node->keys.size() && key > node->keys[i]) {
            i++;
        }

        return searchKey(node->children[i], key);
    }

    BPlusTreeNode* findLeafNode(BPlusTreeNode* node, int key) {
        if (!node) {
            return nullptr;
        }

        if (node->children.empty()) {
            return node;
        }

        int i = 0;
        while (i < node->keys.size() && key > node->keys[i]) {
            i++;
        }

        return findLeafNode(node->children[i], key);
    }

    void printTree(BPlusTreeNode* node) {
        if (!node) {
            return;
        }

        for (int key : node->keys) {
            std::cout << key << " ";
        }

        if (!node->children.empty()) {
            std::cout << " | ";
            for (BPlusTreeNode* child : node->children) {
                printTree(child);
            }
        }
    }
};

int main() {
    BPlusTree bplusTree;

    bplusTree.insert(3);
    bplusTree.insert(7);
    bplusTree.insert(1);
    bplusTree.insert(5);
    bplusTree.insert(9);
    bplusTree.insert(2);
    bplusTree.insert(4);

    std::cout << "B+ Tree: ";
    bplusTree.print();
    std::cout << std::endl;

    int searchKey = 5;
    if (bplusTree.search(searchKey)) {
        std::cout << "Found " << searchKey << " in the B+ tree." << std::endl;
    } else {
        std::cout << searchKey << " not found in the B+ tree." << std::endl;
    }

    int minRange = 3;
    int maxRange = 7;
    std::vector<int> result = bplusTree.rangeQuery(minRange, maxRange);
    std::cout << "Range query (" << minRange << " to " << maxRange << "): ";
    for (int key : result) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    return 0;
}