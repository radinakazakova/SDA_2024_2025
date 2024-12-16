#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

struct Query
{
    int idx, time;
};

struct CompareOrder
{
    bool operator()(const Query& f, const Query& s)
    {
        return f.idx > s.idx;
    }
};

struct Compare
{
    bool operator()(const Query& f, const Query& s)
    {
        return f.time > s.time;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    priority_queue<Query, vector<Query>, CompareOrder> order;
    for(int i = 0; i < N; i++)
    {
        int time;
        cin >>time;
        order.push({i, time});
    }
    
    priority_queue<Query, vector<Query>, Compare> pending;
    
    int currTime = 0;
    int minTime = INT_MAX;
    int maxTime = INT_MIN;
    
    while(!order.empty())
    {
        while(!order.empty() && order.top().idx <= currTime)
        {
            pending.push(order.top());
            order.pop();
        }
        
        if(order.empty() && !pending.empty())
        {
            while(!pending.empty())
            {
                auto inProgress = pending.top();
                pending.pop();
                int totalTime = currTime - inProgress.idx + inProgress.time;
                minTime = min(minTime, totalTime);
                maxTime = max(maxTime, totalTime);
                currTime += inProgress.time;
            }
        }
        
        if(!pending.empty())
        {
            auto inProgress = pending.top();
            pending.pop();
            int totalTime = currTime - inProgress.idx + inProgress.time;
            minTime = min(minTime, totalTime);
            maxTime = max(maxTime, totalTime);
            currTime += inProgress.time;
        }
        else
            currTime++;
    }
    
    cout << minTime << " " << maxTime;
    return 0;
}
