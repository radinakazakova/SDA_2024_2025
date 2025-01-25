#include <bits/stdc++.h>

using namespace std;

bool canMakeNPancakes(size_t time, vector<int>& times, size_t target)
{
    size_t sum = 0;
    for(size_t i = 0; i < times.size(); i++)
    {
        size_t pancakesPerChef = time/times[i];
        sum += pancakesPerChef;
    }
    
    if(sum >= target)
        return true;
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long N;
    cin >> N;
    int K;
    cin >> K;
    
    vector<int> times;
    for(int i = 0; i < K; i++)
    {
        int time;
        cin >> time;
        times.push_back(time);
    }
    
    int maxChef = *max_element(times.begin(), times.end());
    size_t maxTime = maxChef * N;
    size_t minTime = 1;
    size_t resTime = maxTime;
    while(minTime <= maxTime)
    {
        size_t mid = minTime + (maxTime - minTime)/2;
        
        if(canMakeNPancakes(mid, times, N)){
            resTime = mid;
            maxTime = mid - 1;
        }
        else
        {
            minTime = mid + 1;
        }   
    }
    cout << resTime;
    
    return 0;
}
