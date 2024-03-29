class Solution {
public:

int search(vector<int> &nums, int target) {
    if (nums.size() == 0)
        return -1;

    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > nums[high]) {
            if (nums[mid] > target && nums[high] < target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else if (nums[mid] < nums[low]) {
            if (nums[mid] < target && nums[low] > target)
                low = mid + 1;
            else {
                high = mid - 1;
            }
        } else {
            if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}
};