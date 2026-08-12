class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int maxlen = INT_MIN;
        unordered_map<int,int> freq;
        while(j<n)
        {
            freq[nums[j]]++;
            while(freq[nums[j]]>k)
            {
                freq[nums[i]]--;
                i++;
            }
            maxlen = max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};