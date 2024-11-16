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

class Solution {
    public:
    Node* root = nullptr;
    public:
  		Node* _insert(Node* root, int data) {
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

    Node* insert(Node* curr, int data)
    {
        root = _insert(curr, data);
        return root;
    }

	void print(Node *root) {
		if(!root)
            return;
        print(root->rightNode);
        print(root->leftNode);
        if(root == this->root)
            cout << root->data;
        else
            cout << root->data << ';';
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = nullptr;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.print(root);
    return 0;
}
