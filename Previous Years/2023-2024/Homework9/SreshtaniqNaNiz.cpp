//може да се реши и с хеш

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    string s1, s2;
    cin >> s1 >> s2;
    
    size_t s1Size = s1.size();
    size_t size = s2.size() - s1Size;
    int res = 0;
    for(int i = 0; i <= size; i++)
    {
        if(s2[i] != s1[0])
            continue;
        
        bool found = true;
        
        for(int j = 0; j < s1Size; j++)
        {
            if(s2[i + j] != s1[j])
            {
                found = false;
                break;
            }
        }
        
        if(found)
            res++;
    }
    
    cout << res;
    return 0;
}
