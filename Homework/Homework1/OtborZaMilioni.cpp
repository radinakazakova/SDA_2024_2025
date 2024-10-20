#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

bool isUpper(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}

int getNumFromDigit(char ch)
{
    return (ch - '0') + 1;
}

int getNumFromLower(char ch)
{
    return (ch - 'a') + 1 + 10;
}

int getNumFromUpper(char ch)
{
    return (ch - 'A') + 1 + 10 + 26;
}

int getValue(char ch)
{
    if(isUpper(ch))
    {
        return getNumFromUpper(ch);
    }
    else if(isDigit(ch))
    {
        return getNumFromDigit(ch);
    }else
    {
        return getNumFromLower(ch);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    cin >> N;
    
    vector<char> input;
    for(int i = 0; i < N; i++)
    {
        char ch;
        cin >> ch;
        input.push_back(ch);
    }
    
    sort(input.begin(), input.end(), [](const char& left, const char& right)
         {
            int value1 = getValue(left);
            int value2 = getValue(right);
            
            if(value1 < value2)
                return true;
             return false;
         });
        
    for(int i = 0; i < N; i++)
    {
        cout << input[i];
    }
    
    return 0;
}
