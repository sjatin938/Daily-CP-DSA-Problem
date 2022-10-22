//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string S) {
    if (S.length() == 1) {
        return S;
    }
    int i = 0;
    int n = S.length();
    string res;
    while (i < n) {
        if (i > 0 && S[i] == S[i - 1]) {
            i++;
            continue;
        } else {
            res.push_back(S[i]);
            i++;
        }
    }
    return res;
}
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends