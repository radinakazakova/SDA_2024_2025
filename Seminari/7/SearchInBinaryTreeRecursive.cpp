class Solution {
public:
    TreeNode* search(TreeNode* curr, int val)
    {
        if(!curr)
            return nullptr;
        if(curr->val == val)
            return curr;
        else if(curr->val > val)
        {
            return search(curr->left, val);
        }
        else
        {
            return search(curr->right, val);
        }
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return search(root, val);
    }
};
