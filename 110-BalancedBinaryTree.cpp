/*
    Given a binary tree, determine if it is height-balanced.

    For this problem, a height-balanced binary tree is defined 
    as a binary tree in which the depth of the two subtrees of 
    every node never differ by more than 1.
*/
#include <LeetCodeUtil.h>
// class Solution {
// public:
//     // O(nlogn)
//     bool isBalanced(TreeNode* root) {
//         if (root == nullptr) return true;
//         // 左右子树的高度相差不多于1且左右子树都是平衡的
//         return abs(height(root->left) - height(root->right)) <= 1 
//                 && isBalanced(root->left) && isBalanced(root->right);
//     }   
//     int height(TreeNode* root) {
//         if (root == nullptr) return 0;
//         return 1 + max(height(root->left), height(root->right));
//     }
// };
// O(n), 求解高度的时候判断是否平衡
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        height(root, balanced);
        return balanced;
    }   
    // 在求解高度的同时直接判断是否平衡
    int height(TreeNode* root, bool& balanced) {
        if (root == nullptr) return 0;
        int height_left  = height(root->left,  balanced);
        int height_right = height(root->right, balanced);
        if (abs(height_left - height_right) > 1) {
            balanced = false;
            return -1;
        }
        return 1 + max(height_left, height_right);
    }
};
/*
      3
     / \
    9  20
      /  \
     15   7
*/
int main(int argc, char const *argv[]) {
    TreeNode* tree1 = createTree({3, 9, 20, static_cast<int>('#'), static_cast<int>('#'), 15, 7});
    cout << Solution().isBalanced(tree1) << endl;
    return 0;
}

