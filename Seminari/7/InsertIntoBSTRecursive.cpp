class Solution {
public:
    TreeNode* insert(TreeNode* curr, int val)
    {
        if(!curr)
        {
            return new TreeNode(val);
        }
        if(curr->val > val)
        {
            curr->left = insert(curr->left, val);
        }
        else
        {
            curr->right = insert(curr->right, val);
        }
        return curr;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        root = insert(root, val);
        return root;
    }
};
