#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<bool> seen(70000 + 1, false);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if(seen[num])
            continue;
        else
            seen[num] = true;
    }
    int countSize = seen.size();
    
    for(int i = 0; i < countSize; i++)
    {
        if(seen[i])
            cout << i << ' ';
    }
    return 0;
}
