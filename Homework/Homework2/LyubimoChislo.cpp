#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void calculateFriend(long long friendIndex, long long friendsCount)
{
    long long left = 0;
    long long right = friendsCount - 1;
    int depth = 1;
    
    while(left < right)
    {
        long long mid1 = left + (right - left)/3;
        long long mid2 = right - (right - left)/3;
        
        if(friendIndex <= mid1)
        {
            right = mid1;
            depth++;
        }
        else if(friendIndex >= mid2)
        {
            left = mid2;
            depth++;
        }
        else
        {
            cout << depth << '\n';
            return;
        }
    }

    cout << depth << '\n'; //tuk left = right
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int P;
    cin >> P;
    int N;
    cin >> N;
    long long friendsCount = pow(3, P); //най-важното е да се сетиш, че ти трябва long long
    long long invitedFriend;
    
    for(int i = 0; i < N; i++)
    {
        cin >> invitedFriend;
        calculateFriend(invitedFriend - 1, friendsCount);
    }
    
    return 0;
}
