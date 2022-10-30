//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
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

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
 Node *compute(Node *head)

    {


        

        Node *start=head;

 

        if(head->next==NULL)

        {

            return head;

        }

        

        while(start->next!=NULL)

        {

        int flag=0;

            Node *itr=start->next;

            while(itr!=NULL && flag==0)

            {

                   if(itr->data>start->data)

                    {

                        

                        flag=1;

                        

                        start->data=itr->data;

                        start->next=itr->next;

                        break;

                    }

                    else

                    {

                        itr=itr->next;

                    }

            }

           if(flag==0)

           {

               start=start->next;

           }

            

        }

        

        return head;

    }
    
};
   


//{ Driver Code Starts.

int main()
{
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
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends