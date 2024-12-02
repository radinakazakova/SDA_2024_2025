#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin>> N;
    unordered_map<int, int> grandmas; //tema i index
    int minDistance = INT_MAX;
    for(int i = 0; i < N; i++)
    {
        int theme;
        cin >> theme;
        int currDistance = INT_MAX;
        if(grandmas.count(theme))
        {
            currDistance = i - grandmas[theme]; //curr encounter i previous encounter
        }
        grandmas[theme] = i;
        minDistance = min(minDistance, currDistance);
    }
    
    cout << minDistance;
    return 0;
}
