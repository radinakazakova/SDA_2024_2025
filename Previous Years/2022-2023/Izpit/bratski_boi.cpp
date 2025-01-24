#include <bits/stdc++.h>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t res = 0;
    int N;
    cin >> N;
    unordered_map<size_t, size_t> countI;
    
    vector<size_t> I(N);

    for(int i = 0; i < N; i++)
    {
        cin >> I[i];
    }
    
    for(int i = 0; i < N; i++)
    {
        size_t sticker;
        cin >> sticker;
        
        countI[I[i]]++;
        
        if(countI[sticker] == 0)
        {
            res++;
        }
        else
        {
            countI[sticker]--;
        }
    }
    
    cout << res;
    return 0;
}
