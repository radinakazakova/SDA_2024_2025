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
        queue<TreeNode*> el;
        el.push(root);
        int currSum = 0;
        while(!el.empty())
        {
            auto curr = el.front();
            el.pop();

            if(!curr) //важна проверка, тъй като добавяме не проверяваме дали сме вътре още
                continue;
           if(curr->val < low) //спестяваме си тези, които не са в интервала, тъй като имаме bst
           {
            el.push(curr->right);
           }
           else if(curr->val > high)
           {
            el.push(curr->left);
           }
           else //in interval
           {
                currSum += curr->val;
                el.push(curr->left);
                el.push(curr->right);
           }
        }
        return currSum;
    }
};
