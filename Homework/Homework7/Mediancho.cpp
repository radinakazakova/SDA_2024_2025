#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, B;
    cin >> N >> B;

    vector<long long> input(N);

    int idxOfB = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
        if (input[i] == B)
            idxOfB = i;
    }
    
    unordered_map<int, int> count;

    int offset = 0;
    for (int i = idxOfB; i >= 0; i--)
    {
        if (input[i] < B)
            offset--;
        else if (input[i] > B)
            offset++;
        count[offset]++;
    }

    offset = 0;    
    long long res = 0;
    for (int i = idxOfB; i < N; i++)
    {
        if (input[i] < B)
            offset--;
        else if (input[i] > B)
            offset++;
        res += count[-offset];
    }

    cout << res;
    return 0;
}
