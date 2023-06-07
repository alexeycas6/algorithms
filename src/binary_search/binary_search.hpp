#include <vector>

class binary_search {
    static bool good(int val, int target) noexcept { return val <= target; }
    /*
     * array: 1 2 4 7 9 15
     * target: 7
     * good:  t t t t f f
     */
public:
    static int find(const std::vector<int>& nums, int target) noexcept {
        int left = -1;
        int right = nums.size();

        while (right - left > 1) {
            int middle = left + (right - left) / 2;
            if (good(nums[middle], target))
                left = middle;
            else
                right = middle;
        }

        if (left > -1 && nums[left] == target)
            return left;
        else
            return -1;
    }
};