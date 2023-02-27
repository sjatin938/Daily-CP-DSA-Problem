//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Returns maximum repeating element in arr[0..n-1].
	// The array elements are in range from 0 to k-1
int maxRepeating(int *arr, int n, int k) {
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }
    pair<int, int> p(0, 0);
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (p.second < it->second) {
            p.first = it->first;
            p.second = it->second;
        }
        if(p.second == it->second ){
            p.first = min (p.first , it->first);
        }
    }
    return p.first;

}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxRepeating(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends