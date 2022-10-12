class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            int i = 0;
            int j;
            int n = nums.size();
            int k = n - 1;
            vector<vector < int>> ans;

            while (i <= k - 2)
            {
                j = i + 1;
                k = n - 1;
                while (j <= k - 1)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        ans.push_back({ nums[i],
                            nums[j],
                            nums[k] });
                        while (j < k && nums[j] == nums[j + 1])
                            j++;
                        while (k > j && nums[k] == nums[k - 1])
                            k--;
                        j++;
                        k--;
                    }
                    else if (nums[i] + nums[j] + nums[k] < 0)
                        j++;
                    else
                        k--;
                }
                while (i < k - 1 && nums[i] == nums[i + 1])
                {
                    i++;
                }
                i++;
            }
            return ans;
        }
};