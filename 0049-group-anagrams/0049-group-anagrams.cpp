class Solution
{
    public:
        vector<vector < string>> groupAnagrams(vector<string> &strs)
        {
            vector<vector < string>> ans;
            unordered_map<string, vector < string>> freq;

            for (auto &str: strs)
            {
                string s = str;
                sort(s.begin(), s.end());
                freq[s].push_back(str);
            }
            unordered_map<string, vector<string>>::iterator itr;
            for (itr = freq.begin(); itr != freq.end(); itr++)
            {
                ans.push_back(itr->second);
            }
            return ans;
        }
};