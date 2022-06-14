// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


 // } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     unordered_map<int,int>mp;
     Node*ptr=head;
     Node*ptr1=head->next;
     int flag=0;
     while(ptr1!=NULL)
     {
         mp[ptr1->data]++;
         mp[ptr->data]++;
         if(mp[ptr1->data]>1)
         {
             ptr->next=ptr1->next;
             ptr1=ptr1->next;
             flag=1;
         }
         if(flag!=1)
         {
         ptr1=ptr1->next;
         ptr=ptr->next;
         }
         flag=0;
     }
     return head;
    }
};


// { Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}  // } Driver Code Ends