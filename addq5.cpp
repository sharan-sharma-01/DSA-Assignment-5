#include <iostream>
using namespace std;

class Node {
public:
    int coeff, pow;
    Node* next;
    Node(int c, int p) { coeff=c; pow=p; next=NULL; }
};

Node* addPoly(Node* a, Node* b) {
    Node* head = NULL, *tail = NULL;
    while (a && b) {
        Node* t;
        if (a->pow == b->pow) {
            t = new Node(a->coeff + b->coeff, a->pow);
            a = a->next; b = b->next;
        }
        else if (a->pow > b->pow) {
            t = new Node(a->coeff, a->pow);
            a = a->next;
        }
        else {
            t = new Node(b->coeff, b->pow);
            b = b->next;
        }

        if (!head) head = tail = t;
        else { tail->next = t; tail = t; }
    }

    while (a) { 
        Node* t = new Node(a->coeff, a->pow);
        tail->next = t; tail = t; 
        a = a->next;
    }
    while (b) { 
        Node* t = new Node(b->coeff, b->pow);
        tail->next = t; tail = t;
        b = b->next;
    }

    return head;
}

int main() {
    Node* a = new Node(5,2);
    a->next = new Node(4,1);
    a->next->next = new Node(2,0);

    Node* b = new Node(5,1);
    b->next = new Node(5,0);

    Node* r = addPoly(a,b);

    while (r) {
        cout << "[" << r->coeff << "," << r->pow << "] ";
        r = r->next;
    }
}
