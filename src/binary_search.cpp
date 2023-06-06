#include <iostream>
#include <vector>

class solution {
private:
    bool good(int val, int target) { return val <= target; }
    /*
     * array: 1 2 4 7 9 15
     * target: 7
     * good:  t t t t f f
     */
public:
    int binary_search(const std::vector<int>& nums, int target) {
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

int main() {
    std::vector<int> nums = { 1, 2, 4, 7, 9, 15 };
    int target = 7;

    solution s;
    auto idx = s.binary_search(nums, target);
    std::cout << idx << " ";

    return 0;
}