/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes 
from some starting node to any node in the tree along the parent-child connections. 
The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6.
    最大路径和
*/
#include <LeetCodeUtil.h>
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSum(root, ans);
        return ans;
    }
private:
    // root必须被使用
    int maxPathSum(TreeNode* root, int& ans) {
        if (root == nullptr) return INT_MIN;
        int l = maxPathSum(root->left,  ans);
        int r = maxPathSum(root->right, ans);
        ans = max(ans, max(l, 0) + max(r, 0) + root->val); // 左右孩子都可以使用
        return root->val + max(max(l, r), 0); // 0表示左右孩子都不使用
    }
};
int main(int argc, char const *argv[]) {
    TreeNode* tree1 = createTree({1, 2, 3});
    cout << Solution().maxPathSum(tree1) << endl;
    TreeNode* tree2 = createTree({2, -1});
    cout << Solution().maxPathSum(tree2) << endl;
    return 0;
}