/*
    Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

    For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

        1
       / \
      2   2
     / \ / \
    3  4 4  3
    But the following [1,2,2,null,3,null,3] is not:
        1
       / \
      2   2
       \   \
       3    3
    Note:
    Bonus points if you could solve it both recursively and iteratively.
*/
#include <LeetCodeUtil.h>
// 递归实现
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (root == nullptr) return true;
//         return isSymmetric(root->left, root->right);
//     }
// private:
//     bool isSymmetric(TreeNode* left, TreeNode* right) {
//         if (left  == nullptr) return right == nullptr;
//         if (right == nullptr) return  left == nullptr;
//         if (left->val != right->val) return false;
//         return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
//     }
// };
// 非递归实现
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> qLeft, qRight;
        qLeft.push(root->left);
        qRight.push(root->right);
        while (!qLeft.empty() || !qRight.empty()) {
            TreeNode* left = qLeft.front();
            TreeNode* right = qRight.front();
            qLeft.pop();
            qRight.pop();
            if (left == nullptr && right == nullptr) continue;
            if (left == nullptr || right == nullptr) return false;
            if (left->val != right->val) return false;
            qLeft.push(left->left);
            qRight.push(right->right);
            qLeft.push(left->right);
            qRight.push(right->left);
        }
        return true;
    }
};
int main(int argc, char const *argv[]) {
    TreeNode* tree1 = createTree({1, 2, 2, 3, 4, 4, 3});
    cout << Solution().isSymmetric(tree1) << endl;
    TreeNode* tree2 = createTree({1, 2, 2, (int)('#'), 3, (int)('#'), 3});
    cout << Solution().isSymmetric(tree2) << endl;
    return 0;
}
