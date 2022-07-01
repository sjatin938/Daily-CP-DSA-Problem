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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       if(l1==NULL&&l2!=NULL)
        return l2;
        if(l2==NULL &&  l1 !=NULL)
        return l1;
        if(l1==NULL && l2==NULL)
        return NULL;
        ListNode * dummy = new ListNode (0);
        ListNode * t = dummy;
        int carry = 0 ; 
        int sum = 0 ; 
        while(l1&&l2){
            sum =  l1->val+l2->val+carry;
            t->next = new ListNode(sum%10);
            t = t->next;
            carry = sum/10;
            l1= l1->next;
            l2 =l2->next;
        }
            while(l1){
                 sum = carry + l1->val;
                t->next = new ListNode(sum%10);
                t = t->next;
                carry = sum/10;
                l1= l1->next;
                
            }
        while(l2){
            sum = carry + l2->val;
            t->next= new ListNode (sum%10);
            carry = sum/10;
            l2 =l2->next;
            t = t->next;
        }
            if(carry){
                t->next = new ListNode(carry);
                
            }
        
    return dummy->next;
    }
};