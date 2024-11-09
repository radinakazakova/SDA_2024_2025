//решението, което първо се опитах да измисля

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

const size_t MAX= 1e6+2;
size_t N, K;

size_t input[MAX];

int main() {
    cin>>N>>K;
    
    for(size_t i=0; i<N; i++)
    {
        cin>>input[i];
    }
    
    queue<size_t> currentNums; // група с размер К
    size_t currentMin = -1;  
    for(size_t j = 0; j<K; j++)
    {
        currentNums.push(input[j]);
        currentMin = min(input[j], currentMin);
    }

    size_t sum = currentMin;

    for(size_t i = K; i<N; i++)
    {
        if(currentMin==currentNums.front()) //ако ще махаме сегашния минимум
        {
            currentMin = *min_element(input+i-K+1, input+i+1); //преизчисляваме минимума за следващия интервал, +1 защото се мърдаме с 1 от предходния интервал който е (i-k,i)
        }  
      
        currentNums.push(input[i]);
        //currentMin = min(currentNums.back(), currentMin); ненужно

        sum+=currentMin;
        currentNums.pop();  
     }

    cout<<sum;
    return 0;
}
