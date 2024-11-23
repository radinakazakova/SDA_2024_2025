#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

long long dp[10081]{};

void calcSubsets(int cap, vector<int>& lists, int size)
{
  //за всеки елемент в масива добавяме за всяка минута след нея колкото събсета са намерени за допълването и до минутата, в която се намираме
  //демек в масива пазим точно колко подмасива имат сума дадената минута и после ще ги сумираме
    for(int i = 0; i < size; i++)
    {
        auto curr = lists[i];
        for(int j = cap; j >= curr; j--)
        {
            dp[j] = (dp[j] + dp[j - curr]) % 1000000007; //важно тъй като тук overflow-ва
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> lists(N);
    
    for(int i = 0; i < N; i++)
    {
        cin >> lists[i];
    }
    
    dp[0] = 1; //praznoto mnojestvo - база
    
    calcSubsets(10080, lists, N);
    long long res = 0;
    for (int i = 0; i <= 10080; i++) 
    {
        res = (res + dp[i]) % 1000000007;
    }
    cout << res;
    return 0;
}
