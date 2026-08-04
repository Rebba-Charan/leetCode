class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int small = *min_element(begin(nums),end(nums));
        int large = *max_element(begin(nums),end(nums));
        vector<int> ans;
        unordered_set<int> set(nums.begin(),nums.end());
        int n = large - small +1;
        vector<int> present(n,0);
        for(int i = 0;i<n;i++)
        {
            if(set.count(i + small)) present[i] = 1;
        }
        for(int i = 0;i<n;i++)
        {
            if(!present[i]) ans.push_back(i + small);
        }
        return ans;
    }
};