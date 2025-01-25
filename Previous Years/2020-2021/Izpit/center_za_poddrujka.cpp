#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int K,T,B,N;
    cin >> K >> T >> B >> N;
    
    priority_queue<int, vector<int>, greater<int>> priority;

    for(int i = 1; i <= N; i++)
    {
        int query;
        cin >> query;            
        priority.push(query);
        if(i % T == 0 && B)
        {
            B--;
            if(priority.size() >= K)
            {
                for(int j = 0; j < K; j++)
                {
                    cout << priority.top() << " ";
                    priority.pop();
                }
            }
        }
    }
    
    while(B--)
    {
        if(priority.size() >= K)
        {
            for(int j = 0; j < K; j++)
            {
                cout << priority.top() << " ";
                priority.pop();
            }
        }
    }
    return 0;
}
