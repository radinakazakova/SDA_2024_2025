#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Group
{
    int start, end, count;
};

struct Compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    }
};

bool canTransport(vector<Group>& trip, int cap, int size)
{
    std::priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> leaves; //pair(end, count)
    int currCount = 0;
    for(int i = 0; i < size; i++)
    {
        while(!leaves.empty() && leaves.top().first <= trip[i].start) {
            currCount -= leaves.top().second;
            leaves.pop();
        }
        
        leaves.push({trip[i].end, trip[i].count});
        currCount += trip[i].count;
        if(currCount > cap)
            return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int Q;
    cin >> Q;
    
    for(int i = 0; i < Q; i++)
    {
        int N, C;
        cin >> N >> C;
        vector<Group> currTrip;
        for(int j = 0; j < N; j++)
        {
            Group currGroup;
            cin >> currGroup.count >> currGroup.start >> currGroup.end;
            currTrip.push_back(currGroup);
        }
        std::sort(currTrip.begin(), currTrip.end(), [](const Group& lhs, const Group& rhs)
                  {
                     return lhs.start < rhs.start;
                  });
        if(canTransport(currTrip, C, N))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}
