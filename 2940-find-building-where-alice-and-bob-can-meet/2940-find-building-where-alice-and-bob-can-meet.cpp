class Solution {
public:
    void buildTree(int i,int l,int r,vector<int>& segmentTree,vector<int>& heights)
    {
        if(l == r)
        {
            segmentTree[i] = l;
            return;
        }
        int mid = l + (r-l)/2;
        buildTree(2*i+1,l,mid,segmentTree,heights);
        buildTree(2*i+2,mid+1,r,segmentTree,heights);
        int leftindex = segmentTree[2*i+1];
        int rightindex = segmentTree[2*i+2];
        if(heights[leftindex]>=heights[rightindex]) segmentTree[i] = leftindex;
        else segmentTree[i] = rightindex;
        return;
    }
    int RMSQ(int start,int end,int i,int l,int r,vector<int>& segmentTree,vector<int>& heights)
    {
        if(start>r || end <l) return -1; //invalid case
        if(l>=start && r <=end) return segmentTree[i]; // subsequence
        int mid = l + (r-l)/2;
        int leftindex = RMSQ(start,end,2*i+1,l,mid,segmentTree,heights);
        int rightindex = RMSQ(start,end,2*i+2,mid+1,r,segmentTree,heights);
        if(leftindex == -1) return rightindex;
        if(rightindex == -1) return leftindex;
        if(heights[leftindex]>=heights[rightindex]) return leftindex;
        return rightindex;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> segmentTree(4*n);
        buildTree(0,0,n-1,segmentTree,heights);
        int m = queries.size();
        vector<int> arr;
        for(int i = 0;i<m;i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            if(start > end) swap(start,end);
            if(start == end || heights[end] > heights[start]) {
                arr.push_back(end);
                continue;
            }
            int left = end + 1;
            int right = n -1;
            int ans = -1;
            while(left<=right)
            {
                int mid = left + (right - left)/2;
                int value = RMSQ(left,mid,0,0,n-1,segmentTree,heights);
                if(left == right){
                    if(heights[start]<heights[value] && heights[end]<heights[value])
                    {
                        ans = left;
                    }
                    break;
                }
                if(heights[start]<heights[value] && heights[end]<heights[value])
                {
                    ans = value;
                    right = mid;
                }
                else
                {
                    left = mid +1;
                }
            }
            arr.push_back(ans);
        }
        return arr;
    }
};