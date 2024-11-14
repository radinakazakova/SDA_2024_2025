/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* curr, int& sum)
    {
        if(!curr)
            return;

        dfs(curr->right, sum);
        sum += curr->val;
        curr->val = sum;
        dfs(curr->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int currSum = 0;
        dfs(root,currSum);
        return root;
    }
};
