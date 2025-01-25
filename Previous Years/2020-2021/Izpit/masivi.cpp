#include <bits/stdc++.h>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N,M;
    cin >> N >> M;
    
    vector<long long> x(N);
    unordered_set<long long> present;
    for(int i = 0; i < N; i++)
    {
        cin >> x[i];
        present.insert(x[i]);
    }
    
    sort(x.begin(), x.end());
    
    for(int i = 0; i < M; i++)
    {
        long long num;
        cin >> num;
        
        int index;
        if(present.count(num))
        {
            auto lower = std::lower_bound(x.begin(), x.end(), num);
            index = lower - x.begin();
        }
        else
        {
            auto upper = std::upper_bound(x.begin(), x.end(), num);
            index = upper - x.begin();
        }
        
        cout << index << " ";
    }
    return 0;
}
