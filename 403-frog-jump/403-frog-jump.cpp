class Solution {
public:
   bool checkLast(int ind, int k, int n, vector<int>& stones, vector<vector<int>> &dp)
{
    if(ind == n-1)
        return true;
    
    if(dp[ind][k] != -1)
        return dp[ind][k];            

    bool out = false;
    for(int fInd = ind + 1; fInd < n; fInd++)
    {
        if(stones[fInd] == stones[ind] + k - 1)
            out = out | checkLast(fInd, k - 1, n, stones, dp);
        else if(stones[fInd] == stones[ind] + k)
            out = out | checkLast(fInd, k, n, stones, dp);
        else if(stones[fInd] == stones[ind] + k + 1)
            out = out | checkLast(fInd, k + 1, n, stones, dp);
        if(out)
            return dp[ind][k] = 1;
    }
            
    return dp[ind][k] = 0;
}

bool canCross(vector<int>& stones) 
{
    int n = stones.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return checkLast(0, 0, n, stones, dp);
}
};