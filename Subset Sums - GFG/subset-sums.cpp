//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
void subsetSum(vector<int> &arr, int &N, int i, vector<int> &temp, int sum) {
    if (i == N) {
        temp.push_back(sum);
        return ;
    }
    subsetSum(arr, N, i + 1, temp, sum + arr[i]);
    subsetSum(arr, N, i + 1, temp, sum);
}

vector<int> subsetSums(vector<int> arr, int N) {
    if (arr.size() == 0) {
        return {};
    }
    vector<int> temp;
    subsetSum(arr, N, 0, temp, 0);
    sort(temp.begin(), temp.end());
    return temp;

}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends