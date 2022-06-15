class Solution {
public:
vector<int> smallerNumbersThanCurrent(vector<int> &nums) {

    if (nums.size() < 2)
        return {0};

    int idx[101] = {0};
    vector<int> result;
    for (int &num: nums)
        idx[num]++;

    for (int i = 1; i < 101; i++)
        idx[i] += idx[i - 1];

    for (int &num: nums)
        if (num == 0)
            result.push_back(0);
        else
            result.push_back(idx[num-1]);

    return result;
}
};