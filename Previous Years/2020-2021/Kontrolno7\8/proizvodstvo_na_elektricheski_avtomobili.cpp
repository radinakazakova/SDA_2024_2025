#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    priority_queue<int> prices;
    for(int i = 0; i < N; i++)
    {
        int event;
        cin >> event;
        if(event == -1)
        {
            if(prices.empty())
                continue;
            else
            {
                cout << prices.top() << " ";
                prices.pop();
            }
        }
        else
        {
            prices.push(event);
        }
    }
    return 0;
}
