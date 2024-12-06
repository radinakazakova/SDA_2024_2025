#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <utility>

using namespace std;

struct Compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin>>N;
    
    std::priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> times;  // pair (arrives, leaves), за всияки интервали
    
    for(int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;
        
        times.push({start, end});
    }
    
    std::priority_queue<int, vector<int>, std::greater<int>> leaves; //само времената, в които ще напускат
    int time = 0;
    size_t maxLen = 0;
    
    while(!times.empty())
    {
        while(!times.empty() && times.top().first <= time) { //важно за случаи, в които имаме равни начални времена едно след друго
            auto interval = times.top();
            times.pop();
            leaves.push(interval.second);
        }
        
        while(!leaves.empty() && leaves.top() <= time) { //махаме тези, които до текущия момент трябва да са си тръгнали
            leaves.pop(); // pop all ended
        }
        
        maxLen = std::max(maxLen, leaves.size());        
        time = times.top().first; // jump to next start
    }
    
    cout << maxLen;
    return 0;
}
