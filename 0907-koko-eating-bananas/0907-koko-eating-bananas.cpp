class Solution {
public:
bool canEatBananas(vector<int> &piles, int mid, int h) {

    long actualHrs = 0;
    for (int i = 0; i < piles.size(); i++) {
        actualHrs += piles[i] / mid;
        if (piles[i] % mid) {
            actualHrs++;
        }
    }
    return actualHrs <= h;
}

int minEatingSpeed(vector<int> &piles, int h) {

    int n = piles.size();
    int l = 1;
    int r = *max_element(begin(piles), end(piles));


    while (l <= r) {
        int mid = l + ((r - l) >> 1);

        if (canEatBananas(piles, mid, h)) {
            r = mid-1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
};