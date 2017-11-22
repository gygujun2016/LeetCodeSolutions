#ifndef _LEET_CODE_UTIL_H_
#define _LEET_CODE_UTIL_H_
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
// 链表结点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 二叉树结点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 打印vector中的所有元素
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
    for (int i = 0; i < v.size(); ++i) {
        i == 0 ? out << v[i] : cout << ' ' << v[i];
    }
    return out;
}
// 打印二维vector中的所有元素
template <typename T>
ostream& operator<<(ostream& out, const vector<vector<T>>& v) {
    for (int i = 0; i < v.size(); ++i) {
        i == 0 ? out << v[i] : out << '\n' << v[i];
    }
    return out;
}
// 以initializer_list来初始化链表
template <typename T>
ListNode* createList(const initializer_list<T>& v) {
    ListNode dummy(0);
    ListNode* prev = &dummy;
    for (const auto& e : v) {
        prev->next = new ListNode(e);
        prev = prev->next;
    }
    return dummy.next;
}
// 销毁链表
void destroyList(ListNode* &head) {
    ListNode* curr = head, *next;
    while (curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
    head = NULL;
}
// 打印链表元素
ostream& operator<<(ostream& out, const ListNode* list) {
    while (list != NULL) {
        list->next == NULL ? out << list->val : out << list->val << ' ';
        list = list->next;
    }
    return out;
}
// 前序遍历二叉树
void preorderTraverseTree(TreeNode *root) {
    if (root == NULL) return;
    cout << root->val << ' ';
    preorderTraverseTree(root->left);
    preorderTraverseTree(root->right);
}
// 中序遍历二叉树
void inorderTraverseTree(TreeNode *root) {
    if (root == NULL) return;
    inorderTraverseTree(root->left);
    cout << root->val << ' ';
    inorderTraverseTree(root->right);
}
// 后序遍历二叉树
void postorderTraverseTree(TreeNode *root) {
    if (root == NULL) return;
    postorderTraverseTree(root->left);
    postorderTraverseTree(root->right);
    cout << root->val << ' ';
}
// 层序遍历二叉树
void levelorderTraverseTree(TreeNode *root) {
    if (root == NULL) return;
    queue<TreeNode *> q;
    TreeNode *curr;
    q.push(root);
    while (!q.empty()) {
        curr = q.front();
        cout << curr->val << ' ';
        if (curr->left)  q.push(curr->left);
        if (curr->right) q.push(curr->right);
        q.pop();
    }
}
// 根据层序遍历的 vector 构造二叉树递归函数
static TreeNode* createTree(const vector<int>& nums, int n) {
    if (nums[n] == '#') return NULL;
    TreeNode *node = new TreeNode(nums[n]);
    int len = nums.size();
    int left  = n*2 + 1;
    int right = n*2 + 2;
    node->left  = left  < len ? createTree(nums, left)  : NULL;
    node->right = right < len ? createTree(nums, right) : NULL;
    return node;
}
// 根据层序遍历的 initializer_list 构造二叉树
template <typename T>
TreeNode* createTree(const initializer_list<T>& nums) {
    vector<T> v;
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        v.push_back(*it);
    }
    return createTree(v, 0);
}
// 随机数辅助类
class MathUtil {
public:
    // 产生[a, b)之间的随机数
    static int random(int a, int b) {
        assert(b > a);
        return a + rand() % (b-a);
    }
};
struct SrandInitalizer {
    SrandInitalizer() { srand(time(NULL)); }
};
SrandInitalizer _srandinit;
// 时间辅助类
class TimeUtil {
public:
  // 返回当前进程运行的时间 (单位: ms)
  static int getCurrentTimeMs() { return (int)clock() / (CLOCKS_PER_SEC / 1000); }
  // 返回当前进程运行的时间 (单位: us)
  static int getCurrentTimeUs() { return (int)clock() / (CLOCKS_PER_SEC / 1000000); }
};

#endif // _LEET_CODE_UTIL_H_
