class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long int initial = k;
        long long int count = 0;
        int n = nums.size();
        long long int prev = -1;;
        long long int const m = 1000000007;
        long long int num = 0; 
        for(int i = 0;i<n;i++)
            {
                if(initial > nums[i])
                {
                    initial-=nums[i];
                    continue;
                }
                
                num += (((nums[i] - initial) + (k-1)) /k ); 
                initial+= ((((nums[i] - initial) + (k-1)) /k )*k);
                if(prev == -1)
                {
                  count += ((num%m)*((num+1)%m)/2);
                  prev = count;
                }
                else
                {
                count += ((num%m)*((num+1)%m)/2 - prev%m)%m;
                prev = count;
                }
                initial-=nums[i]; 
            }
        return (count%m);
    }
};