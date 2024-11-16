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

    void printSFB(int k) {
        if(k > depth)
            return;
        
        deque<Node*> level;
        level.push_back(root);
        int counter = 0; //следим кога ще сме на level k
        
        while(!level.empty())
        {
            int size = level.size();
            if(counter == k)
            {
                while(!level.empty())
                {
                    cout << level.back()->value << ' '; //отзад напред принтираме - затова с deque
                    level.pop_back();
                }
                break;
            }
            while(size)
            {
                auto curr = level.front();
                level.pop_front();
                if(curr->left)
                    level.push_back(curr->left);
                if(curr->right)
                    level.push_back(curr->right);
                size--;
            }
            counter++;
        }
    }

private:
  
    Node* root;
    int depth = 0; //добавих depth да смята макса на К още при добавянето на нови nodes

    Node* insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            if(!curNode->left && !curNode->right)
                depth++;
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            if(!curNode->left && !curNode->right)
                depth++;
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
    int k;
    cin >> k;
    tree.printSFB(k);
    return 0;
}
