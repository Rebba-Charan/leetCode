class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        string l = to_string(low);
        string r = to_string(high);
        for(int i = l.size();i<=r.size();i++)
        {
            for(int j = 0; j<= 9 - i;j++)
            {
                string temp = s.substr(j,i);
                int num = stoi(temp);
                if(num>=low&& num<=high)
                {
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};