#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> rocks;
    for(int i = 0; i < N; i++)
    {
        int rock;
        cin >> rock;
        rocks.push_back(rock);
    }
    
    sort(rocks.begin(), rocks.end());
    
    for(int i = 0; i < N; i++) //фиксираме големия камък тук
    {    
        int left = 0; //индекс в началото
        int right = N - 1;//индекс в края
       while(left < right) //ще смятаме всички възможности за големия камък, ако не намерим местим съответния индекс
       {
            if(left == i) //не искаме да включваме големия камък, прескачаме го
            {
                left++;
                continue;
            }
            if(right == i)
            {
                right--;
                continue;
            }
            if(rocks[left] + rocks[right] == rocks[i]) //намерихме
            {
                cout << "true";
                return 0;
            }else if(rocks[left] + rocks[right] < rocks[i])
                left++;
            else
                right--;
        }
    }
    cout << "false";
    return 0;
}
