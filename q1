#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

class LinkedList {
public:
    Node* head;

    LinkedList() { head = NULL; }

    void insertBeg(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
    }

    void insertEnd(int x) {
        Node* n = new Node(x);
        if (!head) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }

    void insertAfter(int key, int x) {
        Node* t = head;
        while (t && t->data != key) t = t->next;
        if (!t) return;
        Node* n = new Node(x);
        n->next = t->next;
        t->next = n;
    }

    void insertBefore(int key, int x) {
        if (!head) return;
        if (head->data == key) { insertBeg(x); return; }

        Node* t = head;
        while (t->next && t->next->data != key) t = t->next;
        if (!t->next) return;

        Node* n = new Node(x);
        n->next = t->next;
        t->next = n;
    }

    void delBeg() {
        if (!head) return;
        Node* t = head;
        head = head->next;
        delete t;
    }

    void delEnd() {
        if (!head) return;
        if (!head->next) { delete head; head = NULL; return; }
        Node* t = head;
        while (t->next->next) t = t->next;
        delete t->next;
        t->next = NULL;
    }

    void deleteNode(int key) {
        if (!head) return;
        if (head->data == key) { delBeg(); return; }
        Node* t = head;
        while (t->next && t->next->data != key) t = t->next;
        if (!t->next) return;
        Node* d = t->next;
        t->next = d->next;
        delete d;
    }

    void search(int key) {
        int pos = 1;
        Node* t = head;
        while (t) {
            if (t->data == key) {
                cout << "Found at position " << pos << endl;
                return;
            }
            t = t->next;
            pos++;
        }
        cout << "Not found\n";
    }

    void display() {
        Node* t = head;
        while (t) { cout << t->data << " "; t = t->next; }
        cout << endl;
    }
};

int main() {
    LinkedList l;

    l.insertBeg(10);
    l.insertEnd(20);
    l.insertAfter(10, 15);
    l.insertBefore(20, 18);

    l.display();

    l.delBeg();
    l.delEnd();
    l.deleteNode(15);

    l.display();

    l.search(18);

    return 0;
}
