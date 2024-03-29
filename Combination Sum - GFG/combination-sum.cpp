//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    
void combinationSum(vector<int> &A, int B, vector<vector<int>> &ans, int idx, int &n, vector<int> temp) {
    if (B == 0) {
        ans.push_back(temp);
        return;
    }
    if (B < 0 || idx >= n) {
        return;  /// 8 1 8 6 8
    }
   
    for (int i = idx; i < n; i++) {
         if (i != idx && A[i] == A[i - 1])
            continue;
        temp.push_back(A[i]);
        if (B - A[i] < 0)
            return;
        combinationSum(A, B - A[i], ans, i, n, temp);
        temp.pop_back();
    }
}


vector<vector<int> > combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    vector<int> temp;
    int n = A.size();
    combinationSum(A, B, ans, 0, n, temp);
    return ans;
}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends