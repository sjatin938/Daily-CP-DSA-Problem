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
          struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};

    ListNode *mergeKLists(vector<ListNode *> &lists)
{
	 priority_queue<ListNode *, vector<ListNode *>, compare> g;

	for (auto l : lists)
	{
        if(l)
		g.push(l);
	}
	ListNode *dummy = new ListNode(0);
	ListNode *curr = dummy;
	while (!g.empty())
	{
		ListNode *temp = g.top();
		g.pop();
		curr->next = temp;
		curr = curr->next;

		if (temp->next != NULL)
		{
			g.push(temp->next);
		}
	}
	return dummy->next;
}
};