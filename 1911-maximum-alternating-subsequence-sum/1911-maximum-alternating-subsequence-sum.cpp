class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(int i,vector<int>& nums,int n,int count)
    {
        if(i>=n) return 0;
        if(dp[i][count%2]!=-1) return dp[i][count%2];
        long long sum1 = (count%2 ==0 ? nums[i] : (-nums[i])) + solve(i+1,nums,n,count+1);
        long long sum2 = solve(i+1,nums,n,count);
        return  dp[i][count%2] = max(sum1,sum2);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],accumulate(begin(nums),end(nums),0));
        this->dp.assign(n, vector<long long>(2, -1));
        int count = 0;
        int i = 0;
        long long ans = solve(i,nums,n,count);
        return ans;
    }
};