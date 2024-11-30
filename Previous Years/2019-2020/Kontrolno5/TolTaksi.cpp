#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long N, M;
    cin >> N >> M;
    unordered_map<string, int> toll;
    
    for(long long i = 0; i < N ; i++)
    {
        string city;
        cin >> city;
        int cost;
        cin >> cost;
        
        toll[city] = cost;
    }
    
    long long sum = 0;
    for(long long i = 0; i < M; i++)
    {
        string route;
        cin >> route;
        sum += toll[route];
    }
    
    cout << sum;
    return 0;
}
