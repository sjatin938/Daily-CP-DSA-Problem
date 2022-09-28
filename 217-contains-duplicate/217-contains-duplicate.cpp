class Solution {
public:
   
bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, bool> mp;
    for (auto &x: nums)
        if (mp.find(x) == mp.end())
            mp[x] = 1;
        else
            mp[x] = 0;


    for (auto it : mp)
        if (it.second == 0)
            return true;

    return false;

}
};