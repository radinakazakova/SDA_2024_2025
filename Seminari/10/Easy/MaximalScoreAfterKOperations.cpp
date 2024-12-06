class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        std::priority_queue<int> pq(nums.begin(), nums.end());

        while(k && !pq.empty())
        {
            long long max = pq.top();
            score += max;
            pq.pop();

            pq.push(ceil(max / 3.0));
            k--;
        }

        return score;
    }
};
