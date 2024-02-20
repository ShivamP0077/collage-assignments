#include <iostream>
#include <vector>

const int MAX_KEYS = 3;  // Maximum number of keys in a B-tree node

// B-tree node structure
struct BTreeNode {
    bool is_leaf;
    std::vector<int> keys;
    std::vector<BTreeNode*> children;

    BTreeNode(bool leaf = true) : is_leaf(leaf) {}
};

// B-tree class
class BTree {
private:
    BTreeNode* root;

public:
    BTree() : root(nullptr) {}

    // Function to insert a key into the B-tree
    void insert(int key) {
        if (root == nullptr) {
            root = new BTreeNode();
            root->keys.push_back(key);
        } else {
            if (root->keys.size() == MAX_KEYS) {
                BTreeNode* new_root = new BTreeNode(false);
                new_root->children.push_back(root);
                splitChild(new_root, 0);
                root = new_root;
            }
            insertNonFull(root, key);
        }
    }

    // Function to search for a key in the B-tree
    bool search(int key) {
        return searchKey(root, key);
    }

    // Function to print the B-tree in-order
    void inOrderTraversal() {
        inOrder(root);
    }

private:
    // Helper function to insert a key into a non-full node
    void insertNonFull(BTreeNode* node, int key) {
        int i = node->keys.size() - 1;

        if (node->is_leaf) {
            node->keys.push_back(0);  // Create space for the new key
            while (i >= 0 && key < node->keys[i]) {
                node->keys[i + 1] = node->keys[i];  // Shift keys to the right
                i--;
            }
            node->keys[i + 1] = key;
        } else {
            while (i >= 0 && key < node->keys[i]) {
                i--;
            }
            i++;
            if (node->children[i]->keys.size() == MAX_KEYS) {
                splitChild(node, i);
                if (key > node->keys[i])
                    i++;
            }
            insertNonFull(node->children[i], key);
        }
    }

    // Helper function to split a child node
    void splitChild(BTreeNode* parent, int child_index) {
        BTreeNode* child = parent->children[child_index];
        BTreeNode* new_child = new BTreeNode(child->is_leaf);
        parent->keys.insert(parent->keys.begin() + child_index, child->keys[MAX_KEYS / 2]);  // Move median key to parent
        parent->children.insert(parent->children.begin() + child_index + 1, new_child);      // Add new child

        new_child->keys.assign(child->keys.begin() + (MAX_KEYS / 2) + 1, child->keys.end());     // Copy keys
        child->keys.resize(MAX_KEYS / 2);  // Trim keys

        if (!child->is_leaf) {
            new_child->children.assign(child->children.begin() + (MAX_KEYS / 2) + 1, child->children.end());  // Copy children
            child->children.resize(MAX_KEYS / 2 + 1);                                                         // Trim children
        }
    }

    // Helper function to search for a key in the B-tree
    bool searchKey(BTreeNode* node, int key) {
        if (node == nullptr)
            return false;

        int i = 0;
        while (i < node->keys.size() && key > node->keys[i])
            i++;

        if (i < node->keys.size() && key == node->keys[i])
            return true;
        else if (node->is_leaf)
            return false;
        else
            return searchKey(node->children[i], key);
    }

    // Helper function to perform an in-order traversal of the B-tree
    void inOrder(BTreeNode* node) {
        if (node == nullptr)
            return;

        int i;
        for (i = 0; i < node->keys.size(); i++) {
            if (!node->is_leaf)
                inOrder(node->children[i]);
            std::cout << node->keys[i] << " ";
        }

        if (!node->is_leaf)
            inOrder(node->children[i]);
    }
};

int main() {
    BTree btree;

    // Insert some keys into the B-tree
    btree.insert(3);
    btree.insert(7);
    btree.insert(1);
    btree.insert(5);
    btree.insert(9);
    btree.insert(2);

    // Search for keys in the B-tree
    std::cout << "Search for 5: " << (btree.search(5) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 4: " << (btree.search(4) ? "Found" : "Not Found") << std::endl;

    // Print the B-tree in-order
    std::cout << "In-order traversal of the B-tree: ";
    btree.inOrderTraversal();
    std::cout << std::endl;

    return 0;
}