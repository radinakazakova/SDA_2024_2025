#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int people;
    int k;
    cin >> people >> k;
    
    deque<pair<long long,int>> monotonic;
    long long currSum = 0;
    for(int i = 0; i < people; i++)
    {
        long long rating;
        cin >> rating;
        
        if(!monotonic.empty() && monotonic.front().second < i - k + 1) //po index ako ne e v prozoreca go mahame
            monotonic.pop_front();

        while(!monotonic.empty() && monotonic.back().first >= rating)
                monotonic.pop_back();

        monotonic.push_back({rating, i});
    
        if( i >= k - 1)
            currSum += monotonic.front().first;
    }
    
    cout << currSum;
    return 0;
}
