#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int pointsInInterval(int min, int max, vector<size_t>& points)
{
    auto lower = std::lower_bound(points.begin(), points.end(), min) - points.begin();
    auto upper = std::upper_bound(points.begin(), points.end(), max) - points.begin();
    
    return upper - lower;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int studentsCount;
    int queries;
    cin >> studentsCount >> queries;
    vector<size_t> points(studentsCount);
    
    for(int i = 0; i < studentsCount; i++)
    {
        cin >> points[i];
    }
    
    sort(points.begin(), points.end());
    
    for(int i = 0; i < queries; i++)
    {
        int min, max;
        cin >>min>>max;
         if (min > max)
            cout << 0 << "\n";
         else
            cout << pointsInInterval(min, max, points) << '\n';
    }
    
    return 0;
}
