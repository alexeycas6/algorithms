#include <iostream>
#include "binary_search.hpp"

int main() {
    std::vector<int> nums = { 1, 2, 4, 7, 9, 15 };
    int target = 7;

    auto idx = binary_search::find(nums, target);
    std::cout << idx << " ";

    return 0;
}