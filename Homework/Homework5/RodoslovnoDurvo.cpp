//от Георги

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int value;
    Node* parent = nullptr;
};

Node tree[1000000];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin>>N;
    
    for(int i = 0; i < N-1; i++)
    {
        int parent, child;
        cin >>parent>>child;
        
        tree[child].value = child;
        tree[child].parent = &tree[parent];
        tree[parent].value = parent;
    }
    
    int queries;
    cin >> queries;
    for(int i = 0; i < queries; i++)
    {
        int parent, child;
        cin >>parent>>child;
        
        Node* iter = &tree[child];
        Node* precessor = &tree[parent];
        
        while(iter)
        {
            if(iter == precessor)
            {
                cout << "YES" << '\n';
                break;
            }
            if(iter->value < precessor->value)
            {
                cout << "NO" << '\n';
                break;
            }
            iter = iter->parent;
        }
        
        if(!iter)
        {
            cout << "NO" << '\n';
        }
    }
    
    return 0;
}
