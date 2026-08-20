class Solution {
public:
    void updateTree(int l,int r,int i,int idx,vector<long long >& segmentTree)
    {
        if(l == r)
        {
            segmentTree[i] = 1;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx<=mid)
        {
            updateTree(l,mid,2*i+1,idx,segmentTree);
        }
        else
        {
            updateTree(mid+1,r,2*i+2,idx,segmentTree);
        }
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
        return;
    }
    long long query(int L,int R,int i,int l,int r,vector<long long >& segmentTree)
    {
        if(r<L || l>R) return 0;
        if(L>=l && R<=r)
        {
            return segmentTree[i];
        }
        int mid = L + (R-L)/2;
        long long left = query(L,mid,2*i+1,l,r,segmentTree);
        long long right = query(mid+1,R,2*i+2,l,r,segmentTree);
        return left + right;
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        int n = nums2.size();
        for(int i = 0;i<n;i++)
        {
            map[nums2[i]] = i;
        }
        long long ans = 0;
        vector<long long> segmentTree(4*n);
        updateTree(0,n-1,0,map[nums1[0]],segmentTree); // to update 0th index
        for(int i = 1;i<n-1;i++)
        {
            long long int idx = map[nums1[i]];
            long long int leftcommoncount = query(0,n-1,0,0,idx,segmentTree); // common values in left
            long long int uncommon = i - leftcommoncount;
            long long int righttotalcount = (n-1) - idx;
            long long int rightcommoncount = righttotalcount - uncommon;
            ans+= (leftcommoncount*rightcommoncount);
            updateTree(0,n-1,0,idx,segmentTree);
        }
        return ans;

    }
};