class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int leftsum,int rightsum,int i,int n,vector<int>& nums)
    {
        if(i>=n) return 0;
        if(leftsum > rightsum) return 0;
        if(leftsum == rightsum) return 1;
        if(dp[i][leftsum]!=-1) return dp[i][leftsum];
        bool taken,nottaken;
        taken = solve(leftsum + nums[i],rightsum-nums[i],i+1,n,nums);
        nottaken = solve(leftsum,rightsum,i+1,n,nums);
        return dp[i][leftsum] = (taken || nottaken);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = accumulate(nums.begin(),nums.end(),0);
        dp.assign(n,vector<int>(totalsum,-1));
        return solve(0,totalsum,0,n,nums);
    }
};