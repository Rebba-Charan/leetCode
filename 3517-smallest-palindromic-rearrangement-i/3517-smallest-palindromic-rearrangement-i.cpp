class Solution {
public:
    string rever(string s){
        int left = 0;

    int right = s.length() - 1;

    while (left < right) {

        swap(s[left], s[right]);

        left++;

        right--;

    }
    return s;

    }
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n==1) return s;
        vector<int> alpa(26,0);
        for(char c : s)
        {
            alpa[c-'a']++;
        }
        string ans;
        for(int i=0;i<26;i++)
        {
            int val = alpa[i];
            if(val>1)
            {
                int pair = val/2;
                while(pair!=0)
                {
                    ans+= (i +'a');
                    pair--;
                }
                alpa[i]= val%2;
            }
        }
        string dem = ans ;
        for(int i=0;i<26;i++)
        {
            int val = alpa[i];
            if(val==1)
            {
                ans+= (i +'a');
            }
        }
        if(n%2 == 0 ){
            string rem = rever(ans);
            ans = ans + rem ; 
        }else{
            ans = ans + rever(dem);
        }
        return ans;
        
    }
};