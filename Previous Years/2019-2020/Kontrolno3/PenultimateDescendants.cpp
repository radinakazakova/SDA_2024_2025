//От Стоян

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int value;
    int descendantsCount = 0;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<Node*> toDelete;

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }
    
      bool hasChildren(Node *root) {
        return root->left != NULL || root->right != NULL;
    }


    void deletePenultimateAndPrint() {
        deleteChildrenLeaves(root); //1 обхождане трие всяко отговарящо на условието
        printSorted(root); //1 обхождане за принтене
    }

private:
    void printSorted(Node *root) {
        if (root == NULL)
            return;

        printSorted(root->left);
        cout << root->value << " ";
        printSorted(root->right);
    }
    
    Node* deleteChildrenLeaves(Node *root) {
        if (root == NULL || (root->right == NULL && root->left == NULL)) { //ako e izvun ili e listo - nishto
            return root;
        }
        if (root->left == NULL) { //nalqvo nqma
            if (!hasChildren(root->right)) {//ima li deca po-dolu nadqsno - nqma znachi triem root
                Node *temp = root->right;
                delete root;
                root = temp;
                return root;
            }
            //iterirame kum right zashototo znaem che imame samo right
            root->right = deleteChildrenLeaves(root->right);
        } else if (root->right == NULL) { //nadqsno nqma
            if (!hasChildren(root->left)) { //sled leviq da nqma - triem root
                Node *temp = root->left;
                delete root;
                root = temp;
                return root;
            }
            //kum left zashoto imame samo left
            root->left = deleteChildrenLeaves(root->left);
        } else { //ima dve deca
            if (!hasChildren(root->left) && !hasChildren(root->right)) { //tursim da nqmat decata mu deca - delete root
                root->right->left = root->left; //po-golqmoto da sochi kum po-malkoto
                Node *temp = root->right;
                delete root;
                root = temp;
                return root;
            }
            //iterirame left i right zashoto imame i dvata
            root->right = deleteChildrenLeaves(root->right);
            root->left = deleteChildrenLeaves(root->left);
        }

        return root;
    }
    
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
    tree.deletePenultimateAndPrint();
    return 0;
}
