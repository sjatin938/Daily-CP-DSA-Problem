class Solution {
public:
   bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    if (flowerbed.size() < n) {
        return false;
    }
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);
    int sz = flowerbed.size();

    for (int i = 1; i < sz - 1; i++) {
        if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0) {
            flowerbed[i] = 1;
            n--;
        }
        if (n <= 0)
            return 1;
    }

    return 0;

}
};