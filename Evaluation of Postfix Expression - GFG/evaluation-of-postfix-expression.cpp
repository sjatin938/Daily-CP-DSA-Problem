//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int evaluatePostfix(string S) {
    stack<int> c;

    if (S.length() == 0)
        return 0;
    int i = 0;
    int ans = 0;
    while (i < S.length()) {
        if (S[i] != '+' && S[i] != '-' && S[i] != '/' && S[i] != '*')
            c.push(S[i] - '0');
        else {
            int a = c.top();
            c.pop();
            int b = c.top();
            c.pop();
            
            if (S[i] == '+')
                c.push(a + b);
            if (S[i] == '-')
                c.push(b - a);
            if (S[i] == '/'){
                if(b== 0)
                c.push(0);
                else{
                c.push(b/ a);    
                }
            }
            if (S[i] == '*')
                c.push(a * b);
        }
        i++;
    }
    return c.top();
}
   
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends