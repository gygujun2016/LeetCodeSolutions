/*
    Given an array of integers, return indices of the two numbers 
    such that they add up to a specific target.

    You may assume that each input would have exactly one solution, 
    and you may not use the same element twice.

    Example:
    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
*/
// 思路：hashmap保存数组的元素和下标方便查找
#include <LeetCodeUtil.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;               // 保存nums的元素和下标
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int n = target - nums[i];               // 待查的数
            if (hash.find(n) != hash.end()) {       // 如果找到解
                ans.push_back(hash[n]);
                ans.push_back(i);
                break;                              // 只有一个解，找到就退出
            } else {                                // 如果没有找到则保存该元素和它的下标在hash中
                hash[nums[i]] = i;
            }
        }
        return move(ans);
    }
};
int main(int argc, char const *argv[]) {
    vector<int> vector1{2, 7, 11, 15};
    int target1 = 9;
    cout << Solution().twoSum(vector1, target1) << endl;
    return 0;
}

