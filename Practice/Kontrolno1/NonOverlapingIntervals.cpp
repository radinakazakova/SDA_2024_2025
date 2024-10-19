//търсим мин брой интервали, които да махнем, за да получим интервали, които не се припокриват
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& f,const vector<int>& s){
            return f[0] < s[0]; //сортираме по първа компонента
        });

        int count = 0;

        vector<int> curr = intervals[0]; //vmesto curr може да се използва променлива само за края на интервала

        for(int i = 1; i < intervals.size(); i++)
        {
            if(curr[1] > intervals[i][0]) //overlap
            {
                count++;
                curr[1] = min(curr[1], intervals[i][1]); //update interval, взимаме минималния край (може би защото ако се раздроби на по-малки интервали, махаме по-малко интервали
            }
            else
            {
                curr[1] = intervals[i][1]; //взимаме новия интервал
            }
        }
        return count;
    }
};
