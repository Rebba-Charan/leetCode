class Solution {
public:
    vector<int> dp;
    int solve(int i,vector<int>& cost,int n)
    {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int total_cost = cost[i] + min(solve(i+1,cost,n),solve(i+2,cost,n));
        return dp[i] = total_cost;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n,-1);
        return min(solve(0,cost,n),solve(1,cost,n));
    }
};