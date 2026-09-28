class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,int n,int m,string text1, string text2){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i == n || j == m) return 0;
        int count = 0;
        if(text1[i] == text2[j]){
            count = 1 + solve(i+1,j+1,n,m,text1,text2);
        }else{
            count = max(solve(i+1,j,n,m,text1,text2),solve(i,j+1,n,m,text1,text2));
        }
        return dp[i][j] = count;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(),m = text2.size();
        unordered_set<char> set1,set2;
        for(char c : text1) set1.insert(c);
        for(char c : text2) set2.insert(c);
        if(set1.size() == 1 && set2.size() == 1){
            if(text1[0] == text2[0]) return min(n,m);
            else return 0;
        }
        dp.assign(n+1,vector<int>(m+1,-1));
        return solve(0,0,n,m,text1,text2);
    }
};