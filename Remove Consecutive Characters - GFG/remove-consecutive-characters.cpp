// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends

class Solution{
    public:
    string removeConsecutiveCharacter(string S) {
    if (S.size() == 1) {
        return S;
    }
    char c;
    string ans = "";
    int i = 0;
    int n = S.length();
    while (i < n) {
        c = S[i];
        if (S[i] != S[i - 1]) {
            ans += c;
            i++;
        } else {
            while (S[i] == S[i - 1]) {
                i++;
            }
        }
    }
    return ans;
}
};

// { Driver Code Starts.
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