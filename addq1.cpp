#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) { val = v; next = NULL; }
};

Node* getIntersection(Node* a, Node* b) {
    Node* p = a;
    Node* q = b;
    while (p != q) {
        p = (p == NULL ? b : p->next);
        q = (q == NULL ? a : q->next);
    }
    return p;
}

int main() {
    Node* a = new Node(4);
    a->next = new Node(1);
    Node* inter = new Node(8);
    a->next->next = inter;
    inter->next = new Node(5);

    Node* b = new Node(5);
    b->next = new Node(6);
    b->next->next = new Node(1);
    b->next->next->next = inter;

    Node* ans = getIntersection(a, b);

    if (ans) cout << "Intersected at " << ans->val;
    else cout << "No intersection";

    return 0;
}
