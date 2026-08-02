class Solution {
public:
    int state[501][501];
    int solve(int i,int j,vector<int>& piles)
    {
        if(i>j) return 0;
        if(state[i][j]!=-1)
        {
            return state[i][j];
        }
        int pick_i = piles[i] + min(solve(i+2,j,piles),solve(i+1,j-1,piles));
        int pick_j = piles[j] + min(solve(i+1,j-1,piles),solve(i,j-2,piles));
        return (state[i][j] = max(pick_i,pick_j));
    }
    bool stoneGame(vector<int>& piles) {
        int sum = accumulate(piles.begin(),piles.end(),0);
        int n = piles.size();
        int i = 0;
        int j = n-1;
        memset(state,-1,sizeof(state));
        int alice_choice = solve(i,j,piles);
        if(alice_choice > n/2) return true;
        return false;
    }
};