#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

Node* reverseK(Node* head, int k) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int cnt = 0;

    while (curr && cnt < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    if (next)
        head->next = reverseK(next, k);

    return prev;
}

void print(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);

    head = reverseK(head, 3);
    print(head);
    return 0;
}
