#include <bits/stdc++.h>

using namespace std;

struct Friend
{
    int arrive, leave, index;
    
    bool operator<(const Friend& other)const
    {
        return arrive < other.arrive;
    }
};

struct Guest
{
    int leave;
    int chair;
    
    bool operator<(const Guest& other)const
    {
        return leave > other.leave;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    cin >> N;
    
    vector<Friend> friends(N);
    priority_queue<int, vector<int>, std::greater<int>> availableChairs;
    for(int i = 0; i < N; i++)
    {
        int arrive, leave;
        cin >> arrive >> leave;
        
        friends[i] = {arrive, leave, i};
        availableChairs.push(i);
    }
    int T;
    cin >> T;
    sort(friends.begin(), friends.end());
    
    priority_queue<Guest, vector<Guest>> guests;
    
    for(int i = 0; i < N; i++)
    {
        while(!guests.empty() && friends[i].arrive >= guests.top().leave)
        {
            availableChairs.push(guests.top().chair);
            guests.pop();
        }
        
        if(friends[i].index == T)
        {
            cout << availableChairs.top();
            return 0;
        }
        
        guests.push({friends[i].leave, availableChairs.top()});
        availableChairs.pop();
    }
    return 0;
}
