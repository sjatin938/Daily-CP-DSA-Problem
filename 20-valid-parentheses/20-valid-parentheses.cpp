class Solution {
public:
   bool isValid(string s) {
    stack<int> s1;
    for (char i : s) {
        if (s1.empty() && (i == '}' || i == ')' || i == ']')) {
            return false;
        } else if (i == '{') {
            s1.push('}');
        } else if (i == '(') {
            s1.push(')');
        } else if (i == '[') {
            s1.push(']');
        } else {
            if (s1.top() != i)
                return false;
            else {
                s1.pop();
            }
        }
    }
    if (s1.empty())
        return true;
    return false;
}
};