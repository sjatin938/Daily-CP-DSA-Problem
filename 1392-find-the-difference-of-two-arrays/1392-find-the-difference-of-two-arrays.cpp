class Solution {
public:
vector<vector<int>> findDifference(vector<int> nums1, vector<int> nums2) {
    unordered_set<int> mp1(nums1.begin(), nums1.end());
    unordered_set<int> mp2(nums2.begin(), nums2.end());

    vector<int> d1;
    vector<int> d2;

    for(auto x : mp1){
          if(mp2.find(x) == mp2.end())
            d1.push_back(x);
    }
    for(auto x : mp2){
          if(mp1.find(x) == mp1.end())
            d2.push_back(x);
      
  }
    return {d1, d2};
}
};