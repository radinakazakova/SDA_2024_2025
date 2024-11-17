#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printSFB() {
        deque<Node*> level;
        level.push_back(root);
        bool leftToRight = true;
        
        while(!level.empty())
        {
            int size = level.size();
            if(leftToRight)
            {
                while(size)
                {
                    auto curr = level.front();
                    level.pop_front();
                    size--;
                    cout << curr->value << " ";
                    if(curr->left)
                        level.push_back(curr->left);
                    if(curr->right)
                        level.push_back(curr->right);
                }
                leftToRight = false;
            }
            else
            {
                while(size)
                {
                    auto curr = level.back();
                    level.pop_back();
                    size--;
                    cout << curr->value << " ";
                    
                    if(curr->right)
                        level.push_front(curr->right);
                    if(curr->left)
                        level.push_front(curr->left);                    
                }
                leftToRight = true;
            }
        }
    }

private:
  	//you can write helper functions if needed
    Node* root;

    Node* insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0 ; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
  
    tree.printSFB();
    return 0;
}
