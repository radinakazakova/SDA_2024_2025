#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int people;
    cin >> people;
    
    vector<int> passing;
    for(int i =0; i < people; i++)
    {
        int person;
        cin >> person;
        if(passing.empty()){
            passing.push_back(person);
            continue;
        }
        if(passing.back() < 0 || (passing.back() > 0 && person > 0))
        {
            passing.push_back(person);
            continue;
        }
        if(passing.back() > 0 && person < 0)
        {
            while(!passing.empty() && abs(passing.back()) < abs(person) && passing.back() > 0)
                passing.pop_back();
            if(abs(passing.back()) == abs(person)){
                passing.pop_back();
                continue;
            }
            if(passing.back() < 0 || passing.empty())
                passing.push_back(person);
        }
    }
    
    if(passing.empty())
    {
        cout << '\n';
    }else  
    {
        for(size_t i = 0; i < passing.size(); i++)
        {
            cout << passing[i] << ' ';
        }
    }
    return 0;
}
