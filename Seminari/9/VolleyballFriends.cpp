//unordered set
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int number, N;
    cin >> number >> N;
    unordered_set<int> team;
    team.insert(number);
    int bestFriend;
    for(int i =0; i < N; i++)
    {
        cin >> number >> bestFriend;
        if(team.count(number))
        {
            team.insert(bestFriend);
        }
    }
    
    cout << team.size();
    
    return 0;
}
