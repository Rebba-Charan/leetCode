class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,string& word1,string& word2){
        if(j == word2.size()) return ( word1.size() -i );
        if(i == word1.size()) return (word2.size() - j );
        if(dp[i][j]!=-1) return dp[i][j];
        int count;
        if(word1[i] == word2[j]) count = solve(i+1,j+1,word1,word2);
        else {
            count = 1 + min({solve(i,j+1,word1,word2),solve(i+1,j,word1,word2),solve(i+1,j+1,word1,word2)});
        }
        return dp[i][j] = count;
    }
    int minDistance(string word1, string word2) {
        if(word1 == word2) return 0;
        memset(dp,-1,sizeof(dp));
        // if(word1.size() == 0 || word2.size() == 0){
        //     return max(word1.size(),word2.size());
        // }
        return solve(0,0,word1,word2);
    }
};