/*
    You are given two non-empty linked lists representing two 
    non-negative integers. The digits are stored in reverse order 
    and each of their nodes contain a single digit. Add the two 
    numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, 
    except the number 0 itself.

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
*/

// 思路： 注意讨论三种情况即可
#include <LeetCodeUtil.h>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode *l2) {
        ListNode preHead(0), *prev = &preHead;
        int sum, carry = 0;
        while (l1 || l2 || carry) { // 三种情况一起考虑
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            prev->next = new ListNode(sum % 10);
            prev = prev->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return preHead.next;
    }
};
int main(int argc, char const *argv[]) {
    ListNode* list1 = createList({2, 4, 3});
    ListNode* list2 = createList({5, 6, 4});
    ListNode* list = Solution().addTwoNumbers(list1, list2);
    cout << "l1: " << list1 << endl;
    cout << "l2: " << list2 << endl;
    cout << "ans: " << list << endl;
    return 0;
}

