//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int> arr) {
    int N = arr.size();
    int ans = 0;
    map<int, int> val;
    for (int i = 0; i < N; i++) {
        val[arr[i]] = i;
    }
    vector<int> sortArr;
    sortArr = arr;
    int count = 0;
    sort(sortArr.begin(), sortArr.end());
    for (int i = 0; i < N; i++) {
        if (sortArr[i] != arr[i]) {
            count++;
            swap(arr[i], arr[val[sortArr[i]]]);
            swap(val[arr[i]], val[arr[val[arr[i]]]]);
        }
    }
    return count;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends