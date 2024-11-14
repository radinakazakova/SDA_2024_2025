#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    long long value;
    long long leftIdx;
    long long rightIdx;
};

vector<Node> tree;
vector<long long> negSums, posSums;

void traversal(long long index, long long xCoord) {
    if (index == -1)
        return;

    if (xCoord < 0) {
        if (negSums.size() <= (-xCoord))
            negSums.resize((-xCoord) + 1, 0);
        negSums[-xCoord] += tree[index].value;
    } else {
        if (posSums.size() <= xCoord)
            posSums.resize(xCoord + 1, 0);
        posSums[xCoord] += tree[index].value;
    }

    traversal(tree[index].leftIdx, xCoord - 1);
    traversal(tree[index].rightIdx, xCoord + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        long long value, left, right;
        cin >> value >> left >> right;
        tree.push_back({value, left, right});
    }

    traversal(0, 0);

    for (int i = negSums.size() - 1; i >= 0; i--) {
        if (negSums[i] != 0) {
            cout << negSums[i] << " ";
        }
    }

    for (int i = 0; i < posSums.size(); i++) {
        if (posSums[i] != 0) {
            cout << posSums[i] << " ";
        }
    }

    return 0;
}
