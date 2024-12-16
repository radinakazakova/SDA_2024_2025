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
    
    int N, S;
    cin >> N >> S;
    
    vector<int> input;
    for(int i = 0; i < N; i++)
    {
        long long power;
        cin >> power;
        input.push_back(power);
    }
    
    int count = 0;
    if((input.size() == 1 && input[0] <= S) || input.empty()){
        cout << -1;
        return 0;
    }
    
    priority_queue<long long, vector<long long>, std::greater<long long>> pq(input.begin(), input.end());
    
    while(!pq.empty() && pq.top() < S && (pq.size() > 1))
    {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        
        pq.push(first + 2*second);
        count++;
    }
    
    if(pq.size() == 1 && pq.top() < S)
    {
        cout << -1;
        return 0;
    }
    
    cout << count;
    return 0;
}
