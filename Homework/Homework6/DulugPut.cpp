#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Node{
    long long value;
    long long left;
    long long right;
};

Node tree[4000001];
long long maxSum = LLONG_MIN;

long long dfsSum(int index)
{
    if(index == -1)
        return 0;
    
    long long nodeValue = tree[index].value;
    long long leftMax = dfsSum(tree[index].left);
    long long rightMax = dfsSum(tree[index].right);
    
    long long curr = std::max({nodeValue, nodeValue + rightMax, nodeValue + leftMax});
    maxSum = std::max({maxSum, curr, nodeValue + rightMax + leftMax});
    return curr;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin>>N;
    
    for(int i = 0; i < N; i++)
    {
        long long value, left, right;
        cin>> value >>left >> right;
        
        tree[i] = {value, left, right};
    }
    
    dfsSum(0);
    cout << maxSum;
    return 0;
}
