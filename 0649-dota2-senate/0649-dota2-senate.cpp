class Solution {
public:
bool removalChar(string &senate, char c, int i) {
    bool removalOfLeftIdx = false;
    int idx = (i+ 1) % senate.length();
    while (true) {
        if (senate[idx] == c) {
            if (idx < i) {
                removalOfLeftIdx = 1;
            }
            senate.erase(begin(senate) + idx);
            break;
        }
        idx++;
        idx = idx % senate.length();
    }
    return removalOfLeftIdx;
}

string predictPartyVictory(string senate) {

    int R_count = count(begin(senate), end(senate), 'R');
    int D_count = senate.length() - R_count;
    int idx = 0;

    while (R_count > 0 && D_count > 0) {
        if (senate[idx] == 'R') {
            bool removalOfLeftIdx = removalChar(senate, 'D', idx);
            D_count--;
            if (removalOfLeftIdx) {
                idx--;
            }
        } else {
            bool removalOfLeftIdx = removalChar(senate, 'R', idx);
            R_count--;
            if (removalOfLeftIdx) {
                idx--;
            }
        }
        idx = (idx+1) % senate.length();
    }
    return R_count > D_count ? "Radiant" : "Dire";

}
};