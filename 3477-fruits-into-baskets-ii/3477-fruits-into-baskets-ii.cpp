class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int count = 0;
        vector<int> touched(n,0);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(baskets[j]>=fruits[i] && (!touched[j]))
                {
                    count++;
                    touched[j] = 1;
                    break;
                }
            }
        }
        return (n - count);
    }
};