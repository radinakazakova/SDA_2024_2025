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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) {
            return nullptr;
        }
        
        if(root->val < low) { //ако е извън от low се местим към по-големите стойности - right
            return trimBST(root->right, low, high); //един вид игнорираме текущия и преминаваме към следващото поддърво
        }
        else if(root->val > high) { //аналогично
            return trimBST(root->left, low, high);
        }
        //ако сме вътре, проверяваме за двете поддървета
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
