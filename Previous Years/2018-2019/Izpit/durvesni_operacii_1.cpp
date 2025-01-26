#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node* left = nullptr;
    Node* right = nullptr;
    int value;
    
    Node(int val):value(val){}
};

struct BST
{
    Node* root = nullptr;
    
    bool contains(Node* curr, int x)
    {
        if(!curr)
            return false;

        if(curr->value > x)
            {
                return contains(curr->left, x);
            }
        if(curr->value < x)
            {
                return contains(curr->right, x);
            }
        if(curr->value == x)
                return true;
        
        return false;
    }
    
    Node* _add(Node* curr, int x)
    {
        if(!curr)
            return new Node(x);
        
        if(curr->value > x)
        {
            curr->left = _add(curr->left, x);
        }
        else if(curr->value < x)
        {
            curr->right = _add(curr->right, x);
        }
        
        return curr;
    }
    
    void add(int x)
    {
        if(contains(root, x))
        {
            return;
        }
        
        root = _add(root, x);
    }
    
    void _print(Node* curr)
    {
        if(!curr)
            return;

        cout << curr->value << " ";        
        _print(curr->left);
        _print(curr->right);
    }
    
    void print()
    {
        _print(root);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    BST tree;
    
    for(int i = 0; i < N; i++)
    {
        string action;
        cin >> action;
        
        if(action == "add")
        {
            int num;
            cin >> num;
            tree.add(num);
        }
        else if(action == "print")
        {
            tree.print();
        }
    }
    return 0;
}
