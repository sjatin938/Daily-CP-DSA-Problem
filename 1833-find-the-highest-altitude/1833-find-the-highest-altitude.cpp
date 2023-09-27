class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans =0;
        int maxAns= 0;
        for(auto x : gain){
            ans = ans + x;
            maxAns = max(maxAns ,ans);
        }
        return maxAns;
    }
};