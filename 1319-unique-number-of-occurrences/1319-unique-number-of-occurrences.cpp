class Solution {
public:

bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> m;
    unordered_set<int> s;
    for (auto n: arr) ++m[n];
    
    for(auto x : m){
        s.insert(x.second);
    }
    
    return s.size() == m.size();

}
};