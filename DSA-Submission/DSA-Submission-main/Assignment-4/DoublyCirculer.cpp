#include<iostream>
using namespace std;

class dcList {
public:
    int val;
    dcList* pre;
    dcList* next;

    dcList(int data) {
        val = data;
        pre = nullptr;
        next = nullptr;
    }
};

void insert_end(int data, dcList*& head) {
    if (head == nullptr) {
        dcList* a = new dcList(data);
        a->next = a->pre = a;
        head = a;
        return;
    } else {
        dcList* a = new dcList(data);
        dcList* ptr = head;

        while (ptr->next != head)
            ptr = ptr->next;

        a->next = ptr->next;
        ptr->next = a;
        a->pre = ptr;
        head->pre = a;

        return;
    }
}

void printList(dcList* head) {
    if (head == nullptr)
        return;

    dcList* ptr = head;
    do {
        cout << ptr->val << "->";
        ptr = ptr->next;
    } while (ptr != head);
    cout << "head" << endl;
}

void delete_end(dcList*& head) {
    if (head == nullptr)
        return;

    dcList* ptr = head->pre;
    ptr->pre->next = head;
    head->pre = ptr->pre;

    if (ptr == head) {
        delete ptr;
        head = nullptr;
    } else {
        delete ptr;
    }
}


int main() {
    dcList* head = nullptr;
    insert_end(2, head);
    insert_end(4, head);
    printList(head);

    return 0;
}