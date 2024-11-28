using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_set<int> seen; 
        set<pair<int, int>> results; // Can not use unordered_set with pair, сет с валидните двойки числа, сет, за да държим само unique двойки

        for (int el : nums)
        {
            if (seen.count(el - k)) //за всяко число проверяваме дали ако то е по-голямото в двойката сме срещнали неговото допълнение то к
            {
                results.insert({el - k, el}); //ако сме го срещнали добавяме двойката в резултата
            }
            if (seen.count(el + k)) //аналогично проверяваме за другото му допълнение, ако то е по-малкото и търсим по-голямото дали е било срещнато
            {
                results.insert({el, el + k});
            }
            seen.insert(el); //разгледали сме този елемент вече
        }

        return results.size();
    }
};
