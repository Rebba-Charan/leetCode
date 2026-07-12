class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        unordered_map<int,int> map;
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        int index = 1;
        for(int i = 0;i<n;i++)
        {
            if(map.find(temp[i]) == map.end())
            {
                map[temp[i]] = index;
                index++;
            }
        }
        for(int i = 0;i<n;i++)
        {
            ans[i] = map[arr[i]];
        }
        return ans;

    }
};