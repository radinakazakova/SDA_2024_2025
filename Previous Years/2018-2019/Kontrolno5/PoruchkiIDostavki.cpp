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
    
    size_t N;
    cin >> N;
    
    unordered_map<long long, size_t> orders;
    for(size_t i = 0; i < N; i++)
    {
        long long id;
        cin >> id;
        orders[id]++;
        if(orders[id] == 10)
        {
            orders.erase(id);
        }
    }
    
    size_t uncompletedOrders = orders.size();
    cout << uncompletedOrders << ' ';
    
    int sumProducts = 0;
    for(const auto& order: orders)
    {
        sumProducts += order.second;
    }
    
    cout << sumProducts;
    return 0;
}
