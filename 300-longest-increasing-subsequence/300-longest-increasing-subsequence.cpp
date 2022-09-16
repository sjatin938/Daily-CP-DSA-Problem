class Solution {
public:
        
    int recursionM(int ind,int prev_ind,vector<int>& nums,vector<vector<int>>& dp){
        if(ind==nums.size()) return 0;
        
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        
        // not take
        int notTake=recursionM(ind+1,prev_ind,nums,dp);
        
        //take
        int take=INT_MIN;
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            take=1+recursionM(ind+1,ind,nums,dp);
        }
        
        return dp[ind][prev_ind+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        //return recursion(0,-1,nums); // Recursion
        return recursionM(0,-1,nums,dp);
    }
};