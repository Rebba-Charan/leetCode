class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int> pairxor(2048,0);
        vector<int> triplexor(2048,0);
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            for(int j = i;j<n;j++)
            {
                if(pairxor[nums[i]^nums[j]] == 0) pairxor[nums[i]^nums[j]] = 1;
            }
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<2048;j++)
            {
                if(pairxor[j])
                {
                    triplexor[j^nums[i]] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<2048;i++)
        {
            if(triplexor[i] == 1) ans++;
        }
        return ans;
    }
};