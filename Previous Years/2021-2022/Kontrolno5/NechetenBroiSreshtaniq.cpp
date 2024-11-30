#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    size_t N;
    cin >> N;
    map<long long,size_t> count;
    
    for(size_t i = 0; i< N; i++)
    {
        long long num;
        cin >> num;
        count[num]++;
    }
    
    int res = 0; //ако е long long се чупи единия тест кейс
    for(const auto& num: count)
    {
        if(num.second % 2 != 0)
            res += (num.second * num.first);
    }
    
    cout << res;
    return 0;
}
