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
    ListNode *reverseList(ListNode *head) {

    if (!head || !head->next) {
        return head;
    }
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *r = dummy;
    ListNode *p = head;
    ListNode *q = p->next;
    while (q != NULL) {
        p->next = r;
        r = p;
        p = q;
        q = q->next;
    }
        p->next = r; 
   head->next = NULL;
    return p;
}
};