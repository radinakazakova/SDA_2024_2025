#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

struct Point
{
    int x, y;
};

struct Compare {
    bool operator()(pair<long long, Point>& a, pair<long long, Point>& b) { //важни проверки за тест кейсовете
        if (a.first == b.first) { //ако разстоянията са равни, сравняваме по координати 
            if (a.second.x == b.second.x) //ако х са равни
                return a.second.y > b.second.y; //срявняваме по y
            return a.second.x > b.second.x; 
        }
        return a.first > b.first; //иначе си сравняваме по разстоянията
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    Point origin;
    cin >> origin.x >> origin.y;
    
    int N, K;
    cin >> N >> K;
    
    std::priority_queue<pair<long long,Point>, vector<pair<long long, Point>>, Compare> distances; //pair(distLen, Point)
    
    for(int i = 0; i < N; i++)
    {
        Point curr;
        cin >> curr.x >> curr.y;

      //избягваме използването на sqrt (и pow)
        long long dist = (long long)(curr.x - origin.x)*(curr.x - origin.x) + 
                         (long long)(curr.y - origin.y)*(curr.y - origin.y);
        
        distances.push({dist, curr});
    }
    
    while(K--)
    {
        auto toPrint = distances.top().second;
        cout << toPrint.x << ' ' << toPrint.y << '\n';
        distances.pop();
    }
    
    return 0;
}
