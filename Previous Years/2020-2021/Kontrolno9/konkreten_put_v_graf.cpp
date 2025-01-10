#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int citiesCount;
    cin >> citiesCount;
    unordered_map<int, vector<int>> graph;
    int N;
    for(int i = 0; i < citiesCount; i++)
    {
        cin >> N;
        for(int j = 0; j < N; j++)
        {
            int city;
            cin >> city;
            graph[i].push_back(city);
            graph[city].push_back(i);
        }
    }
    
    int queries;
    cin >> queries;
    for(int i = 0; i < queries; i++)
    {
        int count;
        cin >> count;
        vector<int> order;
        for(int j = 0; j < count; j++)
        {
            int city;
            cin >> city;
            order.push_back(city);
        }
        
        bool hasConnection = false;

        for(int j = 0; j < count - 1; j++)
        {
            hasConnection = false;
            for(auto& n: graph[order[j]])
            {
                if(n == order[j+1])
                {
                    hasConnection = true;
                    break;
                }
            }
            
            if(!hasConnection)
                break;
        }
        
        if(!hasConnection)
        {
            cout << "0" << " ";
        }
        else
        {
            cout << "1" << " ";
        }
    }
    return 0;
}
