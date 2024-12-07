#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Friend {
    int arrives, leaves, idx;

    bool operator<(const Friend& other) {
        return this->arrives < other.arrives;
    }
};

struct Guest {
    int leaves, chair;
};

struct CompareGuests
{
    bool operator()(const Guest& lhs, const Guest& rhs)
    {
        return lhs.leaves > rhs.leaves;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<Friend> friends;
    
    for(int i = 0; i < N; i++)
    {
        Friend fr;
        cin >> fr.arrives >> fr.leaves;
        fr.idx = i;
        
        friends.push_back(fr);
    }
    std::sort(friends.begin(), friends.end()); //sortirame po arrival time

    int T;
    cin >> T;
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> availableChairs;
    
    for(int i = 0; i < N; i++)
    {   
        availableChairs.push(i);
    }

    std::priority_queue<Guest, vector<Guest>, CompareGuests> guests; //minHeap po leaves
    
    for(int i = 0; i < N; i++)
    {
        while(!guests.empty() && guests.top().leaves <= friends[i].arrives)
        {
            availableChairs.push(guests.top().chair);
            guests.pop();
        }
        
        if(friends[i].idx == T)
        {
            cout << availableChairs.top();
            return 0;
        }
        
        guests.push({friends[i].leaves, availableChairs.top()});
        availableChairs.pop();
    }
    
    return 0;
}
