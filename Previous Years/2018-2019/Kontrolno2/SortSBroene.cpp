#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int counting[10001];
int main() {
    int N;
    cin>> N;
    vector<int> input(N);
    for(int i = 0; i < N; i++)
    {
        cin >> input[i];
        int count = counting[input[i]];
        if(count == 0)
        {
            counting[input[i]]++;
        }
    }
    
    for(int i = 0; i < 10001; i++)
    {
        if(counting[i]!=0)
            cout << i << " ";
    }
    return 0;
}
