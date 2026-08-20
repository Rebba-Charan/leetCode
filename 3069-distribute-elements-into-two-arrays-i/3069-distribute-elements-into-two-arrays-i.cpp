class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> L,R;
        L.push_back(nums[0]);
        R.push_back(nums[1]);
        int j = 0,k = 0;
        for(int i = 2;i<nums.size();i++)
        {
            if(L[j] > R[k])
            {
                L.push_back(nums[i]);
                j++;
            }
            else
            {
                R.push_back(nums[i]);
                k++;
            }
        }
        int n = L.size(),m = R.size();
        for(int i = 0;i<n;i++)
        {
            nums[i] = L[i];
        }
        for(int i = n;i<n+ m;i++)
        {
            nums[i] = R[i-n];
        }
        return nums;
    }
};