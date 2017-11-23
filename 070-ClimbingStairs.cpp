/*
    You are climbing a stair case. It takes n steps to reach to the top.
    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
    Note: Given n will be a positive integer.

    Example 1:

    Input: 2
    Output:  2
    Explanation:  There are two ways to climb to the top.

    1. 1 step + 1 step
    2. 2 steps
    Example 2:

    Input: 3
    Output:  3
    Explanation:  There are three ways to climb to the top.

    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step
*/

// 动态规划的题
// dp[i] = d[i-1] + dp[i-2]
#include <LeetCodeUtil.h>
// 普通动态规划解法
// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n+1, 0);
//         dp[0] = 1;
//         dp[1] = 1;
//         for (int i = 2; i <=n; ++i) {
//             dp[i] = dp[i-1] + dp[i-2];
//         }
//         return dp[n];
//     }
// };
// 递归空间优化为O(1)
class Solution {
public:
    int climbStairs(int n) {
        int two = 1;
        int one = 1;
        int cur = 1;
        for (int i = 2; i <=n; ++i) {
            cur = two + one;
            two = one;
            one = cur;
        }
        return cur;
    }
};
// 记忆化递归
// class Solution {
// public:
//     int climbStairs(int n) {
//         m_ = vector<int>(n+1, 0);
//         return numOfSolutions(n);
//     }
// private:
//     int numOfSolutions(int n) {
//         if (n <= 1) return 1;
//         if (m_[n] > 0) return m_[n];
//         m_[n] = numOfSolutions(n-1) + numOfSolutions(n-2);
//         return m_[n];
//     }
//     vector<int> m_;
// };
int main(int argc, char const *argv[]) {
    Solution sol;
    for (int i = 0; i < 46; ++i) {
        cout << sol.climbStairs(i) << endl;
    }
    return 0;
}