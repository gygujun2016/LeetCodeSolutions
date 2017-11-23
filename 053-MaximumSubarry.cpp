/*
    Find the contiguous subarray within an array (containing at least one number) 
    which has the largest sum.

    For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
    the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

// 一维动态规划
// dp[i] = dp[i-1] > 0 ? dp[i-1] + nums[i] : nums[i]
// nums: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
// dp:   [-2, 1, -2, 4,  3, 5, 6,  1, 5]
#include <LeetCodeUtil.h>
// 一维动态规划解法
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         vector<int> dp(nums.size());
//         dp[0] = nums[0];
//         for (int i = 1; i < nums.size(); ++i) {
//             dp[i] = max(dp[i-1]+nums[i], nums[i]);
//         }
//         return *max_element(dp.begin(), dp.end());
//     }
// };
// 优化为O(1)空间复杂度
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum = max(sum+nums[i], nums[i]);
            ans = max(sum, ans);
        }
        return ans;
    }
};
int main(int argc, char const *argv[]){
    Solution s;
    vector<int> v{-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(v) << endl;
    return 0;
}

