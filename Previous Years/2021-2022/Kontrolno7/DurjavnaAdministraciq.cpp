#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    unordered_map<int, int> complaintsCount;
    vector<int> originalOrder;
    queue<int> firstOccurence;
    unordered_set<int> seen;
    
    for(int i = 0; i < N; i++)
    {
        int number;
        cin >> number;
        complaintsCount[number]++;
        originalOrder.push_back(number);
    }
    
    vector<int> res;
    for(int i = 0; i<N; i++)
    {
        int num = originalOrder[i];
        if(complaintsCount[num] == 1) //ako go ima samo vednuj znaem, che trqbva da go dobavim napravo
        {
            res.push_back(num);
        }
        else if(!seen.count(num)) //ako sme sreshtnali za purvi put chislo koeto shte se povtarq
        {
            seen.insert(num); //otbelqzvame che sme go videli
            firstOccurence.push(num); //i zapisvame podrednostta
        }
        //ako sreshtnem povtarqshto se - nishto ne promenqme
    }
    
    while(!firstOccurence.empty()) //dobavqme povtarqshtite se nakraq
    {
        res.push_back(firstOccurence.front());
        firstOccurence.pop();
    }
    
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    
    return 0;
}
