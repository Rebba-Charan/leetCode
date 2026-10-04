class Solution {
public:
    int dp[101][101];
    bool solve(int i,int count,string s){
        if(count<0) return 0;
        if(i == s.size()){
            if(count == 0) return 1;
            else return 0;
        }
        if(dp[i][count]!=-1) return dp[i][count];
        bool ans;
        if(s[i] == '*'){
            ans = solve(i+1,count,s) | solve(i+1,count+1,s) | solve(i+1,count-1,s) ;
        }
        else if(s[i] == '(') ans = solve(i+1,count+1,s);
        else ans = solve(i+1,count-1,s);
        return dp[i][count] = ans;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s);
    }
};