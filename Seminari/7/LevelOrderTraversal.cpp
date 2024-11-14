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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
        return {};
        vector<vector<int>> res;

        queue<TreeNode*> level;
        level.push(root);

        while(!level.empty())
        {
            size_t levelSize = level.size();
            vector<int> currLevel;
            while(levelSize)
            {
                auto curr = level.front();
                level.pop();
                currLevel.push_back(curr->val);

                if(curr->left)
                {
                    level.push(curr->left);
                }
                if(curr->right)
                {
                    level.push(curr->right);
                }

                levelSize--;
            }
            res.push_back(currLevel);
        }
        return res;
    }
};
