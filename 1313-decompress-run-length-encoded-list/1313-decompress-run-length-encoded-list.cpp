class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
     vector<int>ans ; 
        for(int i =0 ; i < nums.size(); i = i+2){
            int k = nums[i] ; 
            while(k>0){
                ans.push_back(nums[i+1]);
                k--;
            }
        }
        return ans ; 
    }
};