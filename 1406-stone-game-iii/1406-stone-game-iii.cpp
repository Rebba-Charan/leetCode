class Solution {
public:
    int dp[50001];
    int solve(int i,vector<int>& nums,int n)
    {
        if((n-i) <=0) return 0;
        if((n-i) == 1) return nums[i];
        if((n-i) == 2) return max(nums[i],nums[i]+nums[i+1]);
        if(dp[i]!=-1) return dp[i];
        int amount1 = nums[i] + min(min(solve(i+2,nums,n),solve(i+3,nums,n)),solve(i+4,nums,n));
        int amount2 = nums[i] + nums[i+1] +  min(min(solve(i+3,nums,n),solve(i+4,nums,n)),solve(i+5,nums,n));
        int amount3 = nums[i] + nums[i+1] + nums[i+2] + min(min(solve(i+4,nums,n),solve(i+5,nums,n)),solve(i+6,nums,n));
        return dp[i] = max(max(amount1,amount2),amount3);
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // if(n<=2) return "Alice";
        memset(dp,-1,sizeof(dp));
        int sum = accumulate(begin(stoneValue),end(stoneValue),0);
        int alice_score = solve(0,stoneValue,n);
        int bob_score = sum - alice_score;
        if(alice_score == bob_score) return "Tie";
        else if(alice_score > bob_score) return "Alice";
        else return "Bob";
    }
};