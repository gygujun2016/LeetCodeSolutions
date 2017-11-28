/*
    Given a binary tree, return the postorder traversal of its nodes' values.

    For example:
    Given binary tree {1,#,2,3},
       1
        \
         2
        /
       3
    return [3,2,1].

    Note: Recursive solution is trivial, could you do it iteratively?
*/
#include <LeetCodeUtil.h>
// 递归方法
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         DFS(root, ans);
//         return ans;
//     }
// private:
//     void DFS(TreeNode* root, vector<int>& ans) {
//         if (root == nullptr) return;
//         DFS(root->left,  ans);
//         DFS(root->right, ans);
//         ans.push_back(root->val);
//     }
// };
// 非递归
class Solution {
public:
    // reverse postorder的过程
    // rev_postroder(root) : 
    //      if not root : return
    //      print(root->val)
    //      rev_postorder(root->right)
    //      rev_postorder(root->left)

    // 用 stack 来模拟上述过程
    // while not stack.empty()
    //      root = stack.top();
    //      print(root->val)
    //      stack.push(root->left)
    //      stack.push(root->right)

    // 得到postorder只需要将rev_postorder反转一下即可
    //  postorder(root) : 
    //      reverse(rev_postorder(root))
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        stack<TreeNode*> s;
        vector<int> ans;
        s.push(root);
        while (!s.empty()) {
            TreeNode* t = s.top();
            s.pop();
            ans.push_back(t->val);
            if (t->left)  s.push(t->left);
            if (t->right) s.push(t->right);
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
};
int main(int argc, char const *argv[]) {
    TreeNode* tree = createTree({1, (int)('#'), 2, (int)('#'), (int)('#'), 3});
    cout << Solution().postorderTraversal(tree) << endl;
    return 0;
}