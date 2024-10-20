//O(n), О(1) памет
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {    //сортира си с О(n) заради ограничението [1...n] - невалидните числа се игнорират в while
            // while се върти, докато неотрицателните числа не си идат на индекса (числото - 1)
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) //ако се размени отрицателно с неотрицателно - прекратява се while
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1) //като нещо липсва връщаме (индекс + 1) = числото
            {
                return i + 1;
            }
        }

        return n + 1; //ако не намерим в масива, значи е следващото число
    }
};
