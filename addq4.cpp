#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

Node* rotateLeft(Node* head, int k) {
    if (!head || !head->next) return head;

    Node* temp = head;
    int len = 1;
    while (temp->next) {
        temp = temp->next;
        len++;
    }

    k = k % len;
    if (k == 0) return head;

    temp->next = head;

    Node* newTail = head;
    for (int i = 1; i < k; i++) newTail = newTail->next;

    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    head = rotateLeft(head, 4);
    printList(head);
}
