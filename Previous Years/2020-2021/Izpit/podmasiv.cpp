#include <bits/stdc++.h>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    queue<int> subarray;
    unordered_set<int> present;
    
    size_t currMax = 0;
    
    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        
        if(present.count(num))
        {
            while(present.count(num))
            {
                present.erase(subarray.front());
                subarray.pop();
            }
        }
        
        subarray.push(num);
        present.insert(num);
        currMax = max(currMax, subarray.size());
    }
    
    cout << currMax;
    return 0;
}
