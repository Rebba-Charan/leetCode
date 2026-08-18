class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2)
        {
            if(nums[0]==nums[1] && k == 1) return -1;
            return max(nums[0],nums[1]);

        }
        unordered_map<int,int> map;
        for(int i = 0;i<=n-k;i++)
        {
            unordered_set<int> set;
            for(int j = i;j< i +k;j++)
            {
                if(set.count(nums[j]) == 0){
                    map[nums[j]]++;
                    set.insert(nums[j]);
                }
            }
        
        }
        int ans = -1;
        for(auto a : map)
        {
            if(a.second == 1) ans = max(ans,a.first);
        }
        return ans;
    }
};