class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return (nums[0]  + 1);
        int maxi = INT_MIN;
        unordered_set<int> set;
        for(int i = 0;i<n;i++) set.insert(nums[i]);
        int sum = nums[0];
        for(int j = 1;j<n;j++)
        {
        if(nums[j] == (nums[j-1]+ 1)) sum+=nums[j];
        else break;
        }
        maxi = max(maxi,sum);
        if(set.count(maxi) == 0) return maxi;
        for(int i = maxi+1 ; i<=51;i++)
        {
            if(set.count(i) == 0 ) return i;

        } 
        return -1;
    }
};