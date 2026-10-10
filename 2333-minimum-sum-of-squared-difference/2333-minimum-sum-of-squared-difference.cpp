class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> arr(n);
        vector<int> diff(1e5+1,0);
        for(int i = 0;i<n;i++){
            arr[i] = abs(nums1[i] - nums2[i]);
            diff[arr[i]]++;
        }
        int k = k1 + k2;
        for(int currdiff = 1e5;currdiff>0 && k>0 ;currdiff--){
            int currop = min(k,diff[currdiff]);
            diff[currdiff]-=currop;
            diff[currdiff-1]+=currop;
            k-=currop;
        }
        long long ans = 0;
        for(long long int i = 0;i<=1e5;i++){
            ans+= (diff[i]* (i*i));
        }
        return ans;
    }
};