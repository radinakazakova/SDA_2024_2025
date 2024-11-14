//с inorder - ляво корен дясно, пазим ги в масив и проверяваме дали са в нарастващ ред
class Solution {
public:
    void dfs(TreeNode* curr, vector<int>& container)
    {
        if(!curr) {
            return;
        }
        
        dfs(curr->left, container);
        container.push_back(curr->val); //добавяме nodes в нарастващ ред, ако е bst
        dfs(curr->right, container);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        dfs(root, inorder);

        for(size_t i = 1; i < inorder.size(); i++) 
        {
            if(inorder[i - 1] >= inorder[i]) //подредени ли са
            {
                return false;
            }
        }
        
        return true;
    }
};
