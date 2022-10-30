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
ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!head) {
        return head;
    }
    ListNode *t = head;
    ListNode *prev = head;

    int i = 0;
    while (t) {
        t = t->next;
        i++;
    }

    i = i - n;
    if (i == 0) {
        return head->next;
    }
    t = head;
    while (i) {
        t = prev;
        prev = prev->next;
        i--;
    }
    t->next = prev->next;
    return head;
}
};