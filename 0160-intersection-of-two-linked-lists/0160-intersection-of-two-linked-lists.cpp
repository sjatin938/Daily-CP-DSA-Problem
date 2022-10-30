/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *q = headB;
    ListNode *p = headA;
        bool flag = 0;
        bool flag1 = 0;
    while (q != p) {
        q = q->next;
        p = p->next;
        if (p == NULL) {
            if(flag ==1)
                return NULL;
            flag = 1;
            
            p = headB;
        }
        if (q == NULL) {
            if(flag1 == 1)
                return NULL;
            flag1 = 1;
            q = headA;
        }
    }
    return p;
}
};