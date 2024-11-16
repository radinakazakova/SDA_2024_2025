#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    
    Node(int val): value(val){}
};

    Node* insertNode(Node* curr, int val)
{
        if(!curr){
            
            return new Node(val);
        }
        
        if(curr->value < val)
        {
            curr->right = insertNode(curr->right, val);
        }
        else   
        {
            curr->left = insertNode(curr->left, val);
        }
        
        return curr;
}

void print(Node* root)
{
    
    if(!root)
        return;
    
    if(root->left && root->right) //проверка тук, защото ако е горе ще скипнем наследниците на nodes, които имат по един наследник, но този 1 наследник може да има 2 наследника
        cout << root->value << ' ';
    print(root->left);
    print(root->right);
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    cin>>T;
    
    for(int i = 0; i<T;i++)
    {
        int N;
        cin >> N;
        
        Node* root = nullptr;
        for(int j = 0; j < N;j++)
        {
            int value;
            cin>>value;
            if(!root){
                root = new Node(value);
            } else {
                root = insertNode(root, value);
            }        
        }
        print(root);
        cout << '\n';
    }
    return 0;
}
