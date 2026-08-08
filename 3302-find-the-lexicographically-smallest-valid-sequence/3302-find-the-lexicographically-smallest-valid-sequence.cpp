class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> MaxRightMatching(n,0);
        int i = n-1;
        int j = m-1;
        int MaxMatch = 0;
        while(i>=0)
        {
            if(j>=0 && word1[i] == word2[j])
            {
                MaxMatch++;
                j--;
            }
            MaxRightMatching[i] = MaxMatch;
            i--;
        }
        i = 0;
        j = 0;
        vector<int> ans;
        bool superPower = 1;
        while(i<n && j<m)
        {
            if(word1[i] == word2[j])
            {
                ans.push_back(i);
                j++;
            }
            else if(superPower && i+1 !=n && MaxRightMatching[i+1] >= (m-j-1))
            {
                ans.push_back(i);
                j++;
                superPower = 0;
            }
            i++;
        }
        if(j == m) return ans;
        return {};
    }
};