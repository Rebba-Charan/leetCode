class Solution {
    int func(int firstLen, int secondLen,vector<int>&prefixsum)
    {
        int maxsum = 0;
        int MLsum = 0;
        for(int j = (secondLen + firstLen -1);j<prefixsum.size();j++)
        { 
            int Rblock = prefixsum[j] - prefixsum[j - secondLen];
            int Lblock = prefixsum[j - secondLen] - ((j - secondLen - firstLen) < 0 ? 0: prefixsum[j - secondLen - firstLen]);
            MLsum = max(MLsum,Lblock);
            maxsum = max(maxsum,MLsum + Rblock); 
        }
        return maxsum;        
    }
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefixsum(n,0);
        prefixsum[0] = nums[0];
        for(int i = 1;i<n;i++)
        {
            prefixsum[i] = nums[i] + prefixsum[i-1];
        }
        int maxsum1 = func(firstLen,secondLen,prefixsum),maxsum2 = func(secondLen,firstLen,prefixsum);
        // MLsum = prefixsum[secondLen - 1];
        // MRsum = prefixsum[firstLen - 1] - prefixsum[secondLen-1];
        // for(int j = (firstLen -1 + secondLen);j<n;j++)
        // {
        //     int Rblock = prefixsum[j] - prefixsum[j - firstLen];
        //     int Lblock = prefixsum[j - firstLen] - ((j - firstLen - secondLen) < 0 ? 0: prefixsum[j - firstLen - secondLen]);
        //     MLsum = max(MLsum,Lblock);
        //     maxsum2 = max(maxsum2,MLsum + Lblock); 
        // }
        return max(maxsum1,maxsum2);        
    }
};