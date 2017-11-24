/*
    Given a binary tree, find its minimum depth.

    The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
    // 最树的最小深度，注意叶子结点的条件: 左右子树都为空
*/
#include <LeetCodeUtil.h>
// DFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr)  return 1 + minDepth(root->right); // 没有左子树深度取决于有右子树
        if (root->right == nullptr) return 1 + minDepth(root->left);  // 没有右子树深度取决于有左子树
        return 1 + min(minDepth(root->left), minDepth(root->right));  // 同时具有左子树和右子树则取深度最小的
    }
};
// BFS
// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         if (root == nullptr) return 0;
//         queue<TreeNode*> q;
//         q.push(root);
//         int level = 0;
//         bool flag = true;
//         while (!q.empty() && flag) {
//             ++level;
//             int n = q.size();
//             for (int i = 0; i < n; ++i) {
//                 TreeNode* t = q.front();
//                 q.pop();
//                 if (t->left)  q.push(t->left);
//                 if (t->right) q.push(t->right);
//                 if (t->left == nullptr && t->right == nullptr) {
//                      flag = false;
//                      break;
//                 }
//             }
//         }
//         return level;
//     }
// };
int main(int argc, char const *argv[]) {
    TreeNode* tree = createTree({1, 2});
    cout << Solution().minDepth(tree) << endl;
    return 0;
}
