class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto&x : nums)
            mp[x]++;
        int ans =0;

        for(auto&x : mp){
            if(x.second == 1)
            return -1;

            int rem = x.second%3;
            int val = x.second/3;
            if(rem>0)
                val++;
                ans = ans+val;
        }

        return ans;
    }
};