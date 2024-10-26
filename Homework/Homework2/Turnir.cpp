#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    int Q;
    cin >> N >> Q;
    
    vector<int> weights(N);
    for(int i = 0; i< N;  i++)
    {
        cin >> weights[i];
    }
    
    std::sort(weights.begin(), weights.end());
    
    int maxWeight;
    int minWeight;
    for(int i = 0; i < Q ; i++)
    {
        cin >> minWeight >> maxWeight;
        if (minWeight > maxWeight)
            cout << 0 << "\n";
        else{
            auto lower = std::lower_bound(weights.begin(), weights.end(), minWeight);
            auto upper = std::upper_bound(weights.begin(), weights.end(), maxWeight);
        
            cout << size_t(upper - lower) << '\n';
        }
    }
       
    return 0;
}
