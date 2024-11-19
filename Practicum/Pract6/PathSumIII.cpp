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
// memoization be like.....
class Solution {
    void dfs(TreeNode* node, long targetSum, int& ans, int originalTargetSum, bool first){
        if(!node){
            return;
        }

        if(node->val == targetSum){ //намаляваме targetsum с value всеки път затова тук ще получим решение
            ++ans;
        }

        dfs(node->left, targetSum - node->val, ans, originalTargetSum, false); //откъдето сме започнали проверяваме наляво
        if(first){
            dfs(node->left, originalTargetSum, ans, originalTargetSum, true); //за следващия node проверяваме ако той е първи
        }
        //Аналогично
        dfs(node->right, targetSum - node->val, ans, originalTargetSum, false);
        if(first){
            dfs(node->right, originalTargetSum, ans, originalTargetSum, true);
        }
    }

public:
    int pathSum(TreeNode* root, long targetSum) {
        int ans = 0;
        dfs(root, targetSum, ans, targetSum, true);
        return ans;
    }
};
