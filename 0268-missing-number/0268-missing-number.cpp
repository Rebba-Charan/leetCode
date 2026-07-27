class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        {
            if(nums[0] == 0) return 1;
            else return 0;
        }
        int val = 0;
        int value = nums[0];
        for(int i = 1;i<n;i++)
        {
            val = (val^i);
            value = (value^nums[i]);
        }
        val = val^n;
        return val^value;
    }
};