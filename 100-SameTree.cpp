/*
    Given two binary trees, write a function to check if they are the same or not.

    Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

    Example 1:
    Input:     1         1
              / \       / \
             2   3     2   3

            [1,2,3],   [1,2,3]

    Output: true

    Example 2:
    Input:     1         1
              /           \
             2             2

            [1,2],     [1,null,2]

    Output: false

    Example 3:
    Input:     1         1
              / \       / \
             2   1     1   2

            [1,2,1],   [1,1,2]

    Output: false

    判断两个二叉树是否相同:

*/
#include <LeetCodeUtil.h>
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
int main(int argc, char const *argv[]) {
    TreeNode* tree1 = createTree({1, 2, 3});
    TreeNode* tree2 = createTree({1, 2, 3});
    cout << Solution().isSameTree(tree1, tree2) << endl;
    TreeNode* tree3 = createTree({1, 2});
    TreeNode* tree4 = createTree({1, static_cast<int>('#'), 2});
    cout << Solution().isSameTree(tree3, tree4) << endl;
    TreeNode* tree5 = createTree({1, 2, 1});
    TreeNode* tree6 = createTree({1, 1, 2});
    cout << Solution().isSameTree(tree5, tree6) << endl;
    return 0;
}
