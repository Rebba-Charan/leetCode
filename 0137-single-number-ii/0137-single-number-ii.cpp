class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int k = 0;k<=31;k++)
        {
            int temp = (1<<k);
            int countone = 0;
            for(int val : nums)
            {
                if((val & temp) == 0)
                {
                }
                else countone++;
            }
            if((countone%3) == 1)
            {
                ans = (ans | temp);
            }
        }
        return ans;
    }
};