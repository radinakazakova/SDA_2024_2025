#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    
    Node(int value): value(value){}
};

class Tree
{
    Node* root = nullptr;
    
    Node* _insert(Node* curr, int value)
    {
        if(!curr)
            return new Node(value);
        if(curr->value < value)
            curr->right = _insert(curr->right, value);
        else if(curr->value > value)
            curr->left = _insert(curr->left, value);
        
        return curr;
    }
    
    void find(Node* root, int& K, int& value) //връща стойността на к-тото най-голямо, за да го търсим по стойност за да го изтрием
    {
       if(!root || K<=0)
           return;
        
        find(root->right, K, value);
        if(--K == 0)
        {
            value = root->value;
            return;
        }
        find(root->left, K, value);
    }
     Node* deleteNode(Node* root, int key) {
        if(!root) {
            return nullptr;
        }
        
        if(root->value > key) {
            root->left = deleteNode(root->left, key);
        }
        else if(root->value < key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if(!root->left && !root->right) {
                return nullptr;
            }
            if(!root->left) {
                return root->right;
            }
            if(!root->right) {
                return root->left;
            }
            
            auto iter = root->right;
            while(iter->left) {
                iter = iter->left;
            }
            swap(root->value, iter->value);
            root->right = deleteNode(root->right, iter->value);
        }
        
        return root;
    }
    
    void print(Node* root)
    {
        if (!root) 
            return;
        queue<Node*> level;
        level.push(root);
        while (!level.empty()) {
            Node* curr = level.front();
            level.pop();
            cout << curr->value << " ";
           
            if (curr->left) 
                level.push(curr->left); 
            if (curr->right) 
                level.push(curr->right);    
        }
    }
    
    public:
    void insert(int value)
    {
        root = _insert(root, value);
    }
    
    void findKthBiggestAndDelete(int K)
    {
        int KthValue = -1;
        find(root, K, KthValue);
        deleteNode(root, KthValue);
    }
    void print()
    {
        print(root);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    Tree tree;
    for(int i = 0; i < N; i++)
    {
        int value;
        cin >> value;
        tree.insert(value);
    }
    
    tree.findKthBiggestAndDelete(K);
    tree.print();
    return 0;
}
