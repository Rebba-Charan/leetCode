class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1){
            return nums[0]%k == 0 ? 1 : 0;
        }
        int max_len = 0;
        for(int i = 0;i<n;i++){
            unordered_set<int> set;
            int sum = 0;
            for(int j = i;j<n;j++){
                sum+=nums[j];
                set.insert(((2*nums[j])%k + k)%k);
                int value = (sum%k + k)%k;
                if(set.count(value) || value == 0 ) max_len = max(max_len,j-i+1);
            }
        }
        return max_len;
    }
};