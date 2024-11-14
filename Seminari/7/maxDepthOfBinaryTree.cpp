class Solution {
public:

    int findDepth(TreeNode* curr, int depth)
    {
        if(!curr)
            return depth;
        
        return max(findDepth(curr->left, depth+1), findDepth(curr->right, depth+1));
    }
    int maxDepth(TreeNode* root) {
        return findDepth(root, 0);
    }
};
