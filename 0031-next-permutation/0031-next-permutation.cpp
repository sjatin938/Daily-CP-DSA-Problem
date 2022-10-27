class Solution
{
    public:
        void nextPermutation(vector<int> &nums)
        {
            if (nums.size() < 2)
            {
                return;
            }
            int i = nums.size() - 1;
            for (; i > 0; i--)
            {
                if (nums[i] > nums[i - 1])
                {
                    break;
                }
            }
            if (i == 0)
            {
                reverse(nums.begin(), nums.end());
                return;
            }

            int lastIdx = i;
            int temp;
            for (; lastIdx < nums.size(); lastIdx++)
            {
                if (nums[i - 1] < nums[lastIdx] && nums[lastIdx] <= nums[i])
                {
                    temp = lastIdx;
                }
            }
            swap(nums[i - 1], nums[temp]);
            sort(nums.begin() + i, nums.end());
            return;
        }
};