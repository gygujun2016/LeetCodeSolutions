/*
    Given a binary tree, return the level order traversal of its nodes' values. 
    (ie, from left to right, level by level).

    For example:
    Given binary tree [3,9,20,null,null,15,7],
      3
     / \
    9  20
      /  \
     15   7
    return its level order traversal as:
    [
    [3],
    [9,20],
    [15,7]
    ]
*/
#include <LeetCodeUtil.h>
// BFS, 典型的二叉树BFS模板
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         if (root == nullptr) return {};
//         vector<vector<int>> ans;
//         queue<TreeNode*> q;
//         q.push(root);
//         while (!q.empty()) {
//             int n = q.size();
//             vector<int> res;
//             for (int i = 0; i < n; ++i) { // 同一层结点的个数
//                 TreeNode* t = q.front();
//                 q.pop();
//                 res.push_back(t->val);
//                 if (t->left)  q.push(t->left);
//                 if (t->right) q.push(t->right);
//             }
//             ans.push_back(res);
//         }
//         return ans;
//     }
// };
// DFS, 典型的二叉树DFS模板
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> res;
        DFS(root, 0, res, ans);
        return ans;
    }
private:
    void DFS(TreeNode* root, int depth, vector<int>& res, vector<vector<int>>& ans) {
        if (root == nullptr) return;
        while (depth >= ans.size()) ans.push_back({});
        ans[depth].push_back(root->val);
        DFS(root->left,  depth+1, res, ans);
        DFS(root->right, depth+1, res, ans); 
    }
};
int main(int argc, char const *argv[]) {
    TreeNode* tree = createTree({3, 9, 20, static_cast<int>('#'), static_cast<int>('#'), 15, 7});
    cout << Solution().levelOrder(tree) << endl;
    return 0;
}