class Solution {
public:
    bool solv(int i,int j,int turn,vector<int>& nums,int p1,int p2)
    {
        if(i>j)
        {
            if(p1>=p2) return true;
            return false;
        }
        return (turn%2 == 0 ? (solv(i+1,j,turn+1,nums,p1,p2+nums[i]) && solv(i,j-1,turn+1,nums,p1,p2+nums[j])) : (solv(i+1,j,turn+1,nums,p1+nums[i],p2)|| solv(i,j-1,turn+1,nums,p1 + nums[j],p2)));
    }
    bool predictTheWinner(vector<int>& nums) {
        int turn = 1;
        int i =0 ;
        int j = nums.size()-1;
        int p1 =0,p2 = 0;
        return solv(i,j,turn,nums,p1,p2);
    }
};