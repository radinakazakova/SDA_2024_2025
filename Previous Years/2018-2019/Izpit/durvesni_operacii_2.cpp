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
    
    Node* _remove(Node* curr, int x)
    {
        if(!curr) //ne go namira
            return nullptr;
        
        if(curr->value > x)
            curr->left = _remove(curr->left, x);
        else if(curr->value < x)
            curr->right = _remove(curr->right, x);
        else
        {
            if(!curr->left && !curr->right)
                return nullptr;
            if(!curr->left)
                return curr->right;
            if(!curr->right)
                return curr->left;
            
            Node* iter = curr->right;
            
            while(iter->left)
            {
                iter = iter->left;
            }
            
            curr->value = iter->value;
            curr->right = _remove(curr->right, curr->value);
        }  
        return curr;
    }
    
    void remove(int x)
    {
        if(!contains(root, x))
            return;
        root = _remove(root, x);
    }
    
    void _print_odd_layers(Node* curr, bool odd)
    {
        deque<Node*> q;
        q.push_back(curr);
        
        while(!q.empty())
        {
            size_t levelSize = q.size();
            
            while(levelSize--)
            {
                auto curr = q.front();
                q.pop_front();
                if(odd)
                    cout << curr->value << " ";
                if(curr->left)
                    q.push_back(curr->left);
                if(curr->right)
                    q.push_back(curr->right);
            }
            odd = !odd;
        }
    }
    
    void print_odd_layers()
    {
        if(!root)
            return;
        _print_odd_layers(root, true);
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
        else if(action == "remove")
        {
            int num;
            cin >> num;
            
            tree.remove(num);
        }
        else if(action == "print_odd_layers")
        {
            tree.print_odd_layers();
        }
    }
    return 0;
}

