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
    ListNode *t = new ListNode(0);

void reverseList(ListNode *head, ListNode *prev) {
    if (head == NULL) {
        t = prev;
        return;
    }
    reverseList(head->next, head);
    head->next = prev;
    return;


}

ListNode *reverseList(ListNode *head) {
if(head==NULL){
    return head;
}
    ListNode *dummy = new ListNode(0) ;
    dummy->next = head;
    reverseList(head, dummy);
    head->next = NULL;
    return t;
}
};