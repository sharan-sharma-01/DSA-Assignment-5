#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

void insert(Node*& head, int x) {
    Node* t = new Node(x);
    t->next = head;
    head = t;
}

int deleteKey(Node*& head, int key) {
    int count = 0;

    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }
    return count;
}

void print(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    insert(head, 1);
    insert(head, 3);
    insert(head, 1);
    insert(head, 2);
    insert(head, 1);
    insert(head, 2);
    insert(head, 1);

    int key = 1;
    int c = deleteKey(head, key);

    cout << "Count: " << c << " , Updated Linked List: ";
    print(head);

    return 0;
}
