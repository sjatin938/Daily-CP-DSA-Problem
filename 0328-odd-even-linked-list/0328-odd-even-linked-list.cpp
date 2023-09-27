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
    ListNode *oddEvenList(ListNode *head) {
    if (!head  || !head->next)
        return head;
    ListNode *p = head;
    ListNode *q = head->next;
    ListNode *q1 = q;
    ListNode *temp = q->next;
    bool flag = 1;
    while (temp) {
        if (flag) {
            p->next = temp;
            p = temp;
            temp = temp->next;
            flag = !flag;
        } else {
            q->next = temp;
            q = temp;
            temp = temp->next;
            flag = !flag;
        }
    }
    q->next = NULL;
    p->next = q1;
    return head;
}
};