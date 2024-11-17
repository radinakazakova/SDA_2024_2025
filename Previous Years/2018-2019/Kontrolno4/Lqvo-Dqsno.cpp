#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *leftNode;
        Node *rightNode;
        Node(int d) {
            data = d;
            leftNode = NULL;
            rightNode = NULL;
        }
};

int countLeft = 0;
int countRight = 0;

class Solution {
    public:
    
    void dfs(Node* root)
    {
        if(!root)
            return;

        if(root->leftNode)
            countLeft++;
        dfs(root->leftNode);
        if(root->rightNode)
            countRight++;
        dfs(root->rightNode);
    }
    
	void leftRight(Node *root) {
        dfs(root);
        cout << "[" << countLeft << "," << countRight << "]";
    }
    
    Node* insert(Node* root, int data) {
                if(root == NULL) {
                    return new Node(data);
                } else {
                    Node* cur;
                    if(data <= root->data) {
                        cur = insert(root->leftNode, data);
                        root->leftNode = cur;
                    } else {
                        cur = insert(root->rightNode, data);
                        root->rightNode = cur;
                   }

                   return root;
               }
            }
}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.leftRight(root);
    return 0;
}
