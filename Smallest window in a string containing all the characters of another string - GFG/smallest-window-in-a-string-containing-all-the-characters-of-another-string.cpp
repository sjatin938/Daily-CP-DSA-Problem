// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
   string smallestWindow(string s, string p) {
    if (p.length() > s.length()) {
        return "-1";
    }

    unordered_map<char, int> hash;
    for (int i = 0; i < p.length(); ++i) {
        hash[p[i]]++;
    }
    int num_of_element = hash.size();

    int i = 0;
    int j = 0;
    int min_length = s.length();
    int start_index = 0;
    bool found = false;


    while (j < s.length()) {

        if (hash.find(s[j]) != hash.end()) {
            if (--hash[s[j]] == 0) {
                num_of_element--;
            }
        }

        while (num_of_element == 0) {
            found = true;
            if (min_length > j - i + 1) {
                min_length = j - i + 1;
                start_index = i;
            }
            if (hash.find(s[i]) != hash.end()) {
                if (++hash[s[i]] > 0) {
                    num_of_element++;
                }
            }
            i++;
        }

        j++;
    }
    if (found) {
        return s.substr(start_index, min_length);
    }
    return "-1";
}
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends