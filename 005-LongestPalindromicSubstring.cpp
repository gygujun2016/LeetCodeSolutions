/*
    Given a string s, find the longest palindromic substring in s. 
    You may assume that the maximum length of s is 1000.
    
    Example:

    Input: "babad"
    Output: "bab"

    Note: "aba" is also a valid answer.
    Example:

    Input: "cbbd"
    Output: "bb"
*/

// 最长回文子串
// 暴力搜索
#include <LeetCodeUtil.h>
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int len = s.length();
//         if (len == 0) return 0;
//         int maxLen = 0;
//         int start = 0;
//         for (int i = 0; i < len; ++i) {
//             int l, temp;
//             l = longestPalindromeOdd(s, i, temp);
//             if (l > maxLen) {
//                 maxLen = l;
//                 start = temp;
//             }
//             l = longestPalindromeEven(s, i, temp);
//             if (l > maxLen) {
//                 maxLen = l;
//                 start = temp;
//             }
//         }
//         return string(s.begin()+start, s.begin()+start+maxLen);
//     }
// private:
//     // 以start为中心的最长回文
//     int longestPalindromeOdd(string& s, int center, int& start) {
//         int maxLen = 1, step = 1;
//         start = center;
//         while (center-step >= 0 && center+step < s.length() && s[center-step] == s[center+step]) {
//             maxLen += 2;
//             start = center-step;
//             ++step;
//         }
//         return maxLen;
//     }
//     // 以start和start+1为中心的回文
//     int longestPalindromeEven(string& s, int center, int& start) {
//         if (start+1 >= s.length()) return 0;
//         int maxLen = 0, step = 0;
//         start = center;
//         while (center-step >= 0 && center+1+step < s.length() && s[center-step] == s[center+1+step]) {
//             maxLen += 2;
//             start = center-step;
//             ++step;
//         }
//         return maxLen;
//     }
// };

// 动态规划
//      b  a  b  a  d  
//   b  T  F  T  F  F
//   a     T  F  T  F
//   b        T  F  F
//   a           T  F
//   d              T
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int dp[len][len];
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (i == j) {
                    dp[i][j] = 1;
                    continue;
                }
                if (j == i +1) {
                    dp[i][j] = s[i] == s[j] ? 1 : 0;
                    continue;
                }
                dp[i][j] = 0;
            }
        }
        for (int l = 2; l <= len; ++l) {
            for (int i = 0; i < len-l; ++i) {
                dp[i][i+l] = s[i] == s[i+l] ? dp[i+1][i+l-1] : 0;
            }
        }
        int maxLen = 0, from = 0;
        for (int i = 0; i < len; ++i) {
            int start = i, stop = len-1;
            while (dp[i][stop] == 0) --stop;
            if (stop-start+1 > maxLen) {
                maxLen = stop-start+1;
                from = start;
            }
        }
        return string(s.begin()+from, s.begin()+from+maxLen);
    }
};
int main(int argc, char const *argv[]) {
    string s1("babad");
    string s2("cbbd");
    string s3("bb");
    string s4("ccc");
    string s5("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
    cout << Solution().longestPalindrome(s1) << endl;
    cout << Solution().longestPalindrome(s2) << endl;
    cout << Solution().longestPalindrome(s3) << endl;
    cout << Solution().longestPalindrome(s4) << endl;
    cout << Solution().longestPalindrome(s5) << endl;
    return 0;
}