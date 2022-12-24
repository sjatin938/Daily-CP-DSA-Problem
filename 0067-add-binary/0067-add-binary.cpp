class Solution {
public:
     string addBinary(string a, string b) {
        int p = a.length() - 1;
        int q = b.length() - 1;
        int carry = 0;
        string r = "";
        while (p >= 0 || q >= 0 || carry )
        {
            carry += (p >= 0) ? a[p--] - '0' : 0;
            carry += (q >= 0) ? b[q--] - '0': 0;
            r = char(carry % 2+ '0') + r;
            carry /= 2;
        }
        return r;
       
    }
};