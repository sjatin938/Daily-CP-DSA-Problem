// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
int minSwaps(vector<int> &nums) {
    vector<pair<int, int> > arrSort;
    for (int i = 0; i < nums.size(); i++) {
        arrSort.push_back({nums[i], i});
    }
    sort(arrSort.begin(), arrSort.end());
    int minSwap = 0;
    int i = 0;
    while (i < nums.size()) {
        if (i == arrSort[i].second) {
            i++;
            continue;
        } else {
            minSwap++;
            swap(arrSort[i], arrSort[arrSort[i].second]);
        }
    }
    return minSwap;
}
};

// { Driver Code Starts.
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
}  // } Driver Code Ends