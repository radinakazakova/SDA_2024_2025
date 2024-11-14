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

    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        vector<int> container;

        int depth = 0;
        queue<TreeNode*> level; //ще итерираме по нива, държим ги в опашка
        level.push(root);

        while(!level.empty())
        {
            size_t levelSize = level.size();

            while(levelSize - 1) //-1 за да може последния елемент да е front
            {            
                auto curr = level.front();                
                level.pop();
                if(curr->left)
                    level.push(curr->left);
                if(curr->right)
                    level.push(curr->right);

                levelSize--;
            }
            container.push_back(level.front()->val); //добавяме последния
            //тъй като не сме добавили синовете на текущия, ги добавяме
            if(level.front()->left)
                level.push(level.front()->left);
            if(level.front()->right)
                level.push(level.front()->right);
            //махаме текущия и отиваме на следващото ниво
            level.pop();
        }
        return container;
    }
};
