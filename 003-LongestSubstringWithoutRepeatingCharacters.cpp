/*
    Given a string, find the length of the longest substring without repeating characters.

    Examples:

    Given "abcabcbb", the answer is "abc", which the length is 3.

    Given "bbbbb", the answer is "b", with the length of 1.

    Given "pwwkew", the answer is "wke", with the length of 3. 
    Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

    最长无重复子串
    // 思路： hash[s[i]] 保存s[i]字符最近出现的位置，搞清楚什么时候变更计算无重复子串的起始位置
*/
#include <LeetCodeUtil.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (hash[s[i]] > start) {          // hash[s[i]] > start 说明在start右边有重复字符
                start = hash[s[i]];            // start 跳转到上一次出现s[i]的地方，而此时i-start则为一个无重复子串的长度
            } 
            hash[s[i]] = i;                    // 更新最近出现s[i]的位置
            maxLen = max(maxLen, i-start);     // maxLen为历史最长无重复子串，而i-start则为包含当前字符的最长无重复子串
        }
        return maxLen;
    }
};
int main(int argc, char const *argv[]) {
    string ins1{"abcabcbb"};
    string ins2{"bbbbb"};
    string ins3{"pwwkew"};
    string ins4;
    string ins5("c");
    string ins6("aab");
    cout << Solution().lengthOfLongestSubstring(ins1) << endl;
    cout << Solution().lengthOfLongestSubstring(ins2) << endl;
    cout << Solution().lengthOfLongestSubstring(ins3) << endl;
    cout << Solution().lengthOfLongestSubstring(ins4) << endl;
    cout << Solution().lengthOfLongestSubstring(ins5) << endl;
    cout << Solution().lengthOfLongestSubstring(ins6) << endl;
    return 0;
}