class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // Current subarray sum from start -> how many times can be achieved
        unordered_map<int, int> m;
        m[0] = 1; //при 0 дефоултно трябва да имаме 1, задари (curr - k = 0), тоест curr не сме го добавили още, но е валидно

        int totalCount = 0;
        int currentSum = 0;

        for (int el : nums)
        {
            currentSum += el;

            totalCount += m[currentSum - k]; //мога ли да извадя от текущия subarray толкова, че да направя к (търсим числото, което трябва да извадим и колко пъти го има)
            //числото може да е subarray, тоест колко такива subarray-а има с такава сума
            m[currentSum] += 1;
        }
        return totalCount;
    }
};
