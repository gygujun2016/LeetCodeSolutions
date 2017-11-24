/*
    There are two sorted arrays nums1 and nums2 of size m and n respectively.

    Find the median of the two sorted arrays. 
    The overall run time complexity should be O(log (m+n)).

    Example 1:
    nums1 = [1, 3]
    nums2 = [2]
    The median is 2.0

    Example 2:
    nums1 = [1, 2]
    nums2 = [3, 4]
    The median is (2 + 3)/2 = 2.5
*/

// [0, 1, 2, ..., m1-1, | m1, ..., n1-1] [0, 1, 2, ..., m2-1 | m2, ..., n2-1]
// 二分查找m1，查找条件为nums1[m1] 刚好不小于 nums[m2-1]

#include <Util.h>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        // 保证 n1 <= n2
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        const int k = (n1 + n2 + 1) / 2;    // nums[k-1]或者(nums[k-1]+nums[k])/2 为中位数
        int l = 0, r = n1;                  // 左闭右开区间
        while (l < r) {                     // 二分查找确定m1
            const int m1 = l + (r-l) / 2;
            const int m2 = k - m1;
            if (nums1[m1] < nums2[m2-1]) {
                l = m1 + 1;
            } else {
                r = m1;
            }
        }
        const int m1 = l;
        const int m2 = k - l;
        const int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1-1], m2 <= 0 ? INT_MIN : nums2[m2-1]);
        if ((n1 + n2) % 2 == 1) return c1; // 奇数的情况
        const int c2 = min(m1 >= n1 ? INT_MAX : nums1[m1], m2 >= n2 ? INT_MAX : nums2[m2]);
        return (c1 + c2) * 0.5; // 偶数的情况
    }
};
int main(int argc, char const *argv[]) {
    vector<int> v1{1, 3};
    vector<int> v2{2};
    vector<int> v3{1, 2};
    vector<int> v4{3, 4};
    cout << Solution().findMedianSortedArrays(v1, v2) << endl;
    cout << Solution().findMedianSortedArrays(v3, v4) << endl;
    return 0;
}