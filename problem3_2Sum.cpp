#include <iostream>
#include <vector>
#include <unordered_map>

// This is the optimised solution using unordered_map.
// Time complexity of this approach comes out to be O(n).

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numToIndex;
    std::vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        
        if (numToIndex.find(complement) != numToIndex.end()) {
            result.push_back(numToIndex[complement]);
            result.push_back(i);
            return result;
        }
        
        numToIndex[nums[i]] = i;
    }

    return result;
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = twoSum(nums, target);

    if (result.size() == 2) {
        std::cout << "Indices of the two numbers: " << result[0] << " and " << result[1] << std::endl;
        std::cout << "The two numbers are: " << nums[result[0]] << " and " << nums[result[1]] << std::endl;
    } else {
        std::cout << "No solution found for the given target." << std::endl;
    }

    return 0;
}
