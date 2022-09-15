class Solution {
public:
    int cherryPic(int i,int j1,int j2,vector<vector<int>>& grid,int m,int n,vector<vector<vector<int>>>&dp){
        if(j1<0 || j2<0 || j1>=n || j2>=n)
            return 0;
        if(i==m-1){
            if(j1==j2)
                return grid[i][j1];
            else
                return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        int maxi=-1e8;
        for(int k=-1;k<=1;k++){
            for(int p=-1;p<=1;p++){
                int val=0;
                if(j1==j2)
                    val=grid[i][j1]+cherryPic(i+1,j1+k,j2+p,grid,m,n,dp);
                else
                    val=grid[i][j1]+grid[i][j2]+cherryPic(i+1,j1+k,j2+p,grid,m,n,dp);
                maxi=max(maxi,val);    
            }
        }
        return dp[i][j1][j2]=maxi;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return cherryPic(0,0,n-1,grid,m,n,dp);
    }
};
