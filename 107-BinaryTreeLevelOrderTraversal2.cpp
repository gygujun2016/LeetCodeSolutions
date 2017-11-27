/*
    Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

    For example:
    Given binary tree [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
    return its bottom-up level order traversal as:
    [
      [15,7],
      [9,20],
      [3]
    ]
*/
#include <LeetCodeUtil.h>
// 递归
// class Solution {
// public:
//     vector<vector<int>> levelOrderBottom(TreeNode* root) {
//         vector<vector<int>> ans;
//         DFS(root, 0, ans);
//         return vector<vector<int>>(ans.rbegin(), ans.rend());
//     }
// private:
//     void DFS(TreeNode* root, int depth, vector<vector<int>>& ans) {
//         if (root == nullptr) return;
//         while (depth >= ans.size()) ans.push_back({});
//         ans[depth].push_back(root->val);
//         DFS(root->left, depth+1, ans);
//         DFS(root->right, depth+1, ans);
//     }
// };
// 非递归
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int n = q.size();
            ans.push_back({});
            for (int i = 0; i < n; ++i) {
                TreeNode* t = q.front();
                q.pop();
                ans[depth].push_back(t->val);
                if (t->left)  q.push(t->left);
                if (t->right) q.push(t->right);
            }
            ++depth;
        }
        return vector<vector<int>>(ans.rbegin(), ans.rend());
    }
};
int main(int argc, char const *argv[]) {
    TreeNode* tree = createTree({3, 9, 20, (int)('#'), (int)('#'), 15, 7});
    cout << Solution().levelOrderBottom(tree) << endl;

    return 0;
}