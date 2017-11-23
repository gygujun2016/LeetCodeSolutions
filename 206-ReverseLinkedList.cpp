/*
    Reverse a singly linked list.
    单链表反转
*/
#include <LeetCodeUtil.h>
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL, *next;
        while (head) {
            next = head->next; // 保证不断
            head->next = prev; // 指向前面
            prev = head; // 指针后移
            head = next; // 指针后移
        }
        return prev;
    }
};
int main(int argc, char const *argv[]) {
    ListNode* list = createList({1, 2, 3, 4, 5, 6});
    cout << list << endl;
    ListNode* rlist = Solution().reverseList(list);
    cout << rlist << endl;
    return 0;
}
