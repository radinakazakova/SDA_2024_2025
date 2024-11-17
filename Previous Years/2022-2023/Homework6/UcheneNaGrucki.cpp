#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Node
{
    string value; //нормално binary tree ама с думи вместо числа
    Node* left = nullptr;
    Node* right = nullptr;
    
    Node(string value): value(value){}
};

class Tree
{
    Node* root = nullptr;
    
    Node* insert(Node* root, string& word)
    {
        if(!root)
            return new Node(word);
        
        if(root->value < word)
        {
            root->right = insert(root->right, word);
        }
        else if(root->value > word)
        {
            root->left = insert(root->left, word);
        }
        return root;
    }
    
    Node* search(Node* root, string& word)
    {
        if(!root || root->value == word)
        {
            return root;
        }
        return (root->value < word) ? search(root->right, word):search(root->left, word);
    }
public:
    void insertWord(string& word)
    {
        root = insert(root, word);
    }
    
    void searchWord(string& word)
    {
        if(search(root, word))
        {
            cout << "YES" << '\n';
            return;
        }
        cout << "NO" << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin>> N;
    Tree tree;
    for(int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        tree.insertWord(word);
    }
    
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        string word;
        cin >> word;
        tree.searchWord(word);
    }
    return 0;
}
