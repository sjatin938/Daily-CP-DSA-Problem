/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
   Node *flatten(Node *head) {
    if (!head)
        return head;
    stack<Node *> q;
    Node *start = head;
    while (start) {
        if (start->child) {
            if (start->next)
                q.push(start->next);
            start->next = start->child;
            start->child->prev = start;
            start->child = NULL;
        } else if (start->next == NULL && !q.empty()) {
            Node *temp = q.top();
            q.pop();

            start->next = temp;
            temp->prev = start;
        }
        start = start->next;

    }
    return head;
}
};