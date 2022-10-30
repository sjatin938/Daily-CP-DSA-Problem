/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
ListNode *mid(ListNode *p) {
    ListNode *q = p;
    while (q->next && q->next->next) {
        p = p->next;
        q = q->next->next;
    }
    return p;
}

ListNode *reverse(ListNode *head) {
    ListNode *p = NULL;
    ListNode *q = head;
    ListNode *r;
    while (q) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    return p;
}

void reorderList(ListNode *head) {
    if (!head || !head->next || !head->next->next) {
        return;
    }
    ListNode *p = head;
    ListNode *q;
    q = mid(p);
    ListNode *start = q->next;
    q->next = NULL;
    start = reverse(start);
    p = head;
    while (p) {
        ListNode *r = p->next;
        p->next = start;
        if (start)
            start = start->next;
        if(p->next)
        p->next->next = r;
        p = r;
    }
}
};