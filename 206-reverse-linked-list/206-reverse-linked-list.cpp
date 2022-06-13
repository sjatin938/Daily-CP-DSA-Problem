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
    ListNode *headrev = NULL;

    ListNode *helper(ListNode *temp) {
        if (!temp->next) {
            headrev = temp;
            return temp;
        }
        ListNode *prev = helper(temp->next);
        prev->next = temp;
        return temp;
    }

    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *t = helper(head);
        t->next = NULL;
        return headrev;
    }
};