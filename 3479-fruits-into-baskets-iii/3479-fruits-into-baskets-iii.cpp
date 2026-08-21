class Solution {
public:
    void BuildTree(int l,int r,int i,vector<int>& segmentTree,vector<int>& baskets)
    {
        if(l == r)
        {
            segmentTree[i] = baskets[l];
            return;
        }
        int mid = l + (r-l)/2 ; 
        BuildTree(l,mid,2*i+1,segmentTree,baskets);
        BuildTree(mid+1,r,2*i+2,segmentTree,baskets);
        segmentTree[i] = max(segmentTree[2*i+1],segmentTree[2*i+2]);
    }
    bool query(int left,int right,int i ,int value,vector<int>& segmentTree)
    {
        if(segmentTree[i] < value) return false;
        if(left == right)
        {
            segmentTree[i] = -1;
            return true;
        }
        bool placed = true;
        int mid = left + (right - left)/2;
        if(segmentTree[2*i+1] >= value )
        {
            placed = query(left,mid,2*i+1,value,segmentTree);
        }
        else
        {
            placed = query(mid + 1,right,2*i+2,value,segmentTree);
        }
        segmentTree[i] = max(segmentTree[2*i+1],segmentTree[2*i+2]);
        return placed;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
       int n = fruits.size();
       vector<int> segmentTree(4*n);
       BuildTree(0,n-1,0,segmentTree,baskets); 
       int count = 0;
       for(int fruit : fruits)
       {
        if(!query(0,n-1,0,fruit,segmentTree))
        {
            count++;
        }
       }
       return count;
    }
};