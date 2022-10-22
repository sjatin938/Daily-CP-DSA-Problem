class Solution
{
    public:
        bool isValid(string s)
        {
            if (s.length() == 0)
            {
                return 0;
            }
            int n = s.length();
            int i = 0;
            stack<char> check;
            while (i < n)
            {
                if (s[i] == '(')
                    check.push(')');
                else if (s[i] == '{')
                    check.push('}');
                else if (s[i] == '[')
                {
                    check.push(']');
                }
                else if (check.empty())
                    return false;
                else
                {
                    if (check.top() != s[i])
                        return false;
                    check.pop();
                }
                i++;
            }
            return check.empty();
        }
};