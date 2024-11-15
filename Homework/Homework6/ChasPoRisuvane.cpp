#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Node
{
    long long left;
    long long right;
    
    long long leftSize;
    long long rightSize;
};

Node tree[1000001];
long long maxProduct = LLONG_MIN;

void subtreeSize(int index) //smqtame za vseki node kolko nodes ima nadqsno i nalqvo
{
     if (index == -1)
        return;

    long long leftInd = tree[index].left;
    long long rightInd = tree[index].right;

    subtreeSize(leftInd);
    subtreeSize(rightInd);

    if (leftInd != -1)
    {
        tree[index].leftSize = 1 + tree[leftInd].leftSize + tree[leftInd].rightSize; //1 za samiq left
    }
    if (rightInd != -1)
    {
        tree[index].rightSize = 1 + tree[rightInd].leftSize + tree[rightInd].rightSize;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        long long left, right;
        cin >>left >>right;
        tree[i] = {left, right, 0, 0};
    }
    
    subtreeSize(0);
    long long wholeSize = tree[0].leftSize + tree[0].rightSize + 1;
    
    for(int i = 0; i < N; i++)
    {
        auto curr = tree[i];
        long long precessorSize = wholeSize - (1 + curr.leftSize + curr.rightSize);
        if(i == 0) //koren
        {
            if(curr.left == -1 || curr.right == -1) //1 sin
            {
                maxProduct = std::max({maxProduct, wholeSize - 1});
            }
            else // 2 sina
                maxProduct = std::max({maxProduct, curr.leftSize * curr.rightSize});
        }
        else if(curr.left != -1 && curr.right != -1) //2 sina, ne e koren
        {
            maxProduct = std::max({maxProduct, precessorSize * curr.leftSize * curr.rightSize});
        }
        else if(curr.left == -1 && curr.right == -1)//listo
        {
            maxProduct = std::max({maxProduct, precessorSize});
        }
        else if(curr.left == -1) //ne e koren, 1 sin v dqsno
        {
            maxProduct = std::max({maxProduct, curr.rightSize * precessorSize});
        }
        else if(curr.right == -1) // 1 sin v lqvo
        {
            maxProduct = std::max({maxProduct, curr.leftSize * precessorSize});
        }
    }
    
    cout << maxProduct;
    return 0;
}
