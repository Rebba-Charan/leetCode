class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]*nums[0];
        sort(nums.begin(),nums.end());
        int chance = n  - n/2;
        long long int ans = 0;
        int i = 0,j = n-1;
        while(i<=j){
            if(chance !=0){
                chance -=1;
                if(abs(nums[i]) > abs(nums[j])){
                    ans+= (long long )(nums[i]*nums[i]);
                    i++;
                }
                else{
                    ans+=(long long )(nums[j]*nums[j]);
                    j--;
                }
                
            }
            else if(i == j){
                ans-=(long long )(nums[i]*nums[j]);
                i++;
                j--;

            }
            else{
                long long temp = ( (long long )nums[i]*nums[i] + (long long )nums[j]*nums[j]);
                ans-=temp ;
                i++;
                j--;
            }
        }
        return ans;
    }
};