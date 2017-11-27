/*
    Given a binary tree, you need to compute the length of the diameter of the tree. 
    The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
    This path may or may not pass through the root.

    Example:
    Given a binary tree 
              1
             / \
            2   3
           / \     
          4   5    
    Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

    Note: The length of path between two nodes is represented by the number of edges between them.

    二叉树的直径
*/
#include <LeetCodeUtil.h>
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans_ = 0;
        LP(root);
        return ans_;
    }
private:
    int ans_;
    // 通过root结点，且他左右孩子最多使用一次的最长路径
    int LP(TreeNode* root) {
        if (root == nullptr) return -1;
        int l = LP(root->left)  + 1;
        int r = LP(root->right) + 1;
        ans_ = max(ans_, l + r);
        return max(l, r);
    }
};
int main(int argc, char const *argv[]) {
    TreeNode* tree = createTree({1, 2, 3, 4, 5});
    cout << Solution().diameterOfBinaryTree(tree) << endl;
    return 0;
}