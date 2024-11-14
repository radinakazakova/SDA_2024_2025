#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
    long long value;
    long long leftIdx;
    long long rightIdx;
};

bool isValid(vector<Node>& tree, long long index, long min, long max)
{
    if(index == -1)
        return true;
    if(tree[index].value <= min || tree[index].value >= max)
        return false;
    
    return isValid(tree, tree[index].leftIdx, min, tree[index].value) && 
           isValid(tree, tree[index].rightIdx, tree[index].value, max);
}

bool isValidBST(vector<Node>& tree)
{
    return isValid(tree, 0, LLONG_MIN, LLONG_MAX);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int countTrees;
    cin >> countTrees;
    
    for(int i = 0; i < countTrees; i++)
    {
        int nodesCount;
        cin >> nodesCount;
        vector<Node> tree(nodesCount);

        for (int j = 0; j < nodesCount; j++) {
            long long value, left, right;
            cin >> value >> left >> right;
            tree[j] = {value, left, right};
        }
        cout << isValidBST(tree) << '\n';
    }
    return 0;
}
