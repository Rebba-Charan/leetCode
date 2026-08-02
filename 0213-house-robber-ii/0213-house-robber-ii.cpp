class Solution {
public:
    int dp[101];
    int solve(int i,vector<int>& nums,int n)
    {
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        int sum1 = nums[i] + solve(i+2,nums,n);
        int sum2 = solve(i+1,nums,n);
        return dp[i] = max(sum1,sum2);
    }
    int rob(vector<int>& nums) {
      int n = nums.size();
      if(n<=3) return *max_element(begin(nums),end(nums));
      memset(dp,-1,sizeof(dp));  
      int val1 = solve(0,nums,n-2);
      memset(dp,-1,sizeof(dp));  
      int val2 = solve(1,nums,n-1);
      return max(val1,val2);

    }
};