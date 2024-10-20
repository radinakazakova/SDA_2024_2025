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
    cin.ignore();
    vector<pair<string,int>> students(N);
    for(int i = 0; i < N; i++)
    {
        std::getline(std::cin, students[i].first);
    }
    
    for(int i = 0; i<N; i++)
    {
        int score;
        cin >> score;
        students[i].second = score;
    }
    
    sort(students.begin(), students.end(), [](const pair<string,int>& left, const pair<string,int> right)
         {
            if( left.second != right.second)
            {
                return left.second > right.second;
            }else
                return left.first < right.first;
         });
    
    for(int i = 0; i < N; i++)
    {
        cout << students[i].first << ' ' << students[i].second << '\n';
    }
    
    return 0;
}
