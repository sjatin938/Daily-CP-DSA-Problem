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

    ListNode *dOdd = new ListNode(0);
    ListNode *dEven = new ListNode(0);
    ListNode *p = dOdd;
    ListNode *q = dEven;
    bool flag = 1;
    ListNode *temp = head;
    while (temp) {
        if (flag == 1) {
            p->next = temp;
            p = temp;
            temp = temp->next;
            flag = 0;
        } else {
            q->next = temp;
            q = temp;
            temp = temp->next;
            flag = 1;
        }
        p->next = dEven->next;
        if (flag == 0) {
            q->next = NULL;

        }

    }
    return dOdd->next;
}
};