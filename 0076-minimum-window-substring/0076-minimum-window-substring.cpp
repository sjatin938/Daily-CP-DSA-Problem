class Solution
{
    public:
        string minWindow(string s, string t)
        {
            if (s.length() == 0 || t.length() == 0)
                return "";

            vector<int> mp(123, 0);
            for (auto &x: t)
                mp[x]++;

            int maxLen = INT32_MAX;
            int start = 0;
            int left = 0;
            int len = t.length();
            for (int i = 0; i <= s.length(); i++)
            {

                if (len)
                {
                    if (i == s.size())
                        break;
                    mp[s[i]]--;
                    if (mp[s[i]] >= 0)
                    {
                        len--;
                    }
                }
                else
                {

                    if (i - start < maxLen)
                    {
                        maxLen = i - start;
                        left = start;
                    }
                    mp[s[start]]++;
                    if (mp[s[start]] > 0)
                        len++;
                    start++;
                    i--;
                }
            }
            return maxLen == INT32_MAX ? "" : s.substr(left, maxLen);
        }
};