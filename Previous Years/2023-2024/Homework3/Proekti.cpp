#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long themesCount;
    cin >> themesCount;
    
    size_t diff;
    cin >> diff;
    
    vector<size_t> projects(themesCount);
    for(long long i =0; i < themesCount; i++)
    {
        cin >> projects[i];
    }
    
    sort(projects.begin(), projects.end());
    int count = 0;
    
    int iter1 = 0;
    int iter2 = 0;
    
    while(iter1 < themesCount && iter2 < themesCount)
    {
        if(projects[iter2] - projects[iter1] == diff)
        {
            count++;
            iter1++;
            iter2++;
        }
        else if(projects[iter2] - projects[iter1] < diff)
        {
            iter2++;
        }else
            iter1++;
    }
    cout << count;
    return 0;
}
