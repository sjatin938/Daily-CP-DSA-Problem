//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform(string A, string B) {
    if (A.length() != B.length())
        return -1;
    vector<int> count(256, 0);
    for (auto &x: A) {
        count[x]++;
    }
    for (auto &x: B) {
        count[x]--;
    }
    for (auto &x: count)
        if (x != 0)
            return -1;

    int i = A.length() - 1;
    int j = B.length() - 1;
    int res = 0;
    while (i >= 0 && j >= 0) {
        if (A[i] == B[j]) {
            i--;
            j--;
        } else {
            i--;
            res++;
        }
    }
    return res;
}

};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends