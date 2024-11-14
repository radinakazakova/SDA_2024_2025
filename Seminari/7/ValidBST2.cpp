//на всеко поддърво интервалът от стойности се променя, ако елемента е в интервала - окей.

class Solution {
public:
    bool isValid(TreeNode* root, long min, long max) {
        if(!root) {
            return true;
        }
        
        if(root->val <= min || root->val >= max) { //не е в интервала
            return false;
        }
        return isValid(root->left, min, root->val) && isValid(root->right, root->val, max); //проверяваме от двете страни и ъпдейтваме интервалите
    }
    
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};
