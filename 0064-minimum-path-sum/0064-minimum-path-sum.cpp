class Solution {
public:
    int dp[201][201];
    int solve(int i ,int j,vector<vector<int>>& grid,int m,int n){
        if(i == m-1&& j == n-1) return grid[i][j];
        if(i >=m || j>=n) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(solve(i+1,j,grid,m,n),solve(i,j+1,grid,m,n));
    }
    int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    memset(dp,-1,sizeof(dp));
    return solve(0,0,grid,m,n); 
    }
};