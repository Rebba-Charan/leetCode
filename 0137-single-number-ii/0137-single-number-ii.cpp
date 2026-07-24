class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto val : nums)
        {
            map[val]++;
        }
        int ans;
        for(auto a : map)
        {
            if(a.second == 1) {
                ans = a.first;
                break;
            }
        }
        return ans;
    }
};