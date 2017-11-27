/*
    Given a binary tree, return the inorder traversal of its nodes' values.

    For example:
    Given binary tree [1,null,2,3],
       1
        \
         2
        /
       3
    return [1,3,2].

    Note: Recursive solution is trivial, could you do it iteratively?
*/
// 中序遍历的递归实现
#include <LeetCodeUtil.h>
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         DFS(root, ans);
//         return ans;
//     }
// private:
//     void DFS(TreeNode* root, vector<int>& ans) {
//         if (root == nullptr) return;
//         DFS(root->left, ans);
//         ans.push_back(root->val);
//         DFS(root->right, ans);
//     }
// };
// 中序遍历的非递归实现
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while (p || !s.empty()) {
            if (p) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                ans.push_back(p->val);
                p = p->right;
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[]) {
    TreeNode* tree = createTree({1, (int)('#'), 2, (int)('#'), (int)('#'), 3});
    vector<int> treeVector = Solution().inorderTraversal(tree);
    cout << treeVector << endl;
    return 0;
}