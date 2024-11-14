//Тук обхождаме всички елементи - има по-добро решение
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

    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        queue<TreeNode*> el; //за да ги обходим всички (обхождане -> queue)
        el.push(root);
        int currSum = 0;
        while(!el.empty())
        {
            auto curr = el.front();
            el.pop();

            if(curr->val >= low && curr->val <= high)
            {
                currSum += curr->val;
            }
            if(curr->left)
                el.push(curr->left);
            if(curr->right)
                el.push(curr->right);            
        }
        return currSum;
    }
};
