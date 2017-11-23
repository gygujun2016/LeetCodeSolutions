/*
    Reverse digits of an integer.

    Example1: x = 123, return 321
    Example2: x = -123, return -321

    click to show spoilers.

    Note:
    The input is assumed to be a 32-bit signed integer. 
    Your function should return 0 when the reversed integer overflows. // 溢出则返回0

    反转数字，注意负数情况
*/

#include <LeetCodeUtil.h>

class Solution {
public:
    int reverse(int x) { 
        long long res = 0;                             // 注意溢出的情况
        while (x) {
            res = res*10 + x%10; 
            x /= 10;
        }
        return (x < INT_MIN || x > INT_MAX) ? 0 : res; // 考虑溢出的情况
    }
};
int main(int argc, char const *argv[]) {
    cout << Solution().reverse(123) << endl;
    cout << Solution().reverse(-123) << endl;
    cout << Solution().reverse(-12) << endl;
    return 0;
}