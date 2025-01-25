#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    map<vector<int>, int> rowCount; //map zashtoto izpolzwa leksikografski sravneniq, vmesto custom hash funkciq
    //unordered_map ne moje da heshira vector
    for(int i = 0; i < N; i++)
    {
        vector<int> row;
        for(int j = 0; j < M; j++)
        {
            int el;
            cin >> el;
            row.push_back(el);
        }
        rowCount[row]++;
    }
    
    int res = 0;
    for(auto el: rowCount)
    {
        if(el.second == 1)
            res++;
    }
    
    cout << res;
    return 0;
}
