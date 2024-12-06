class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> pq(stones.begin(), stones.end());

        while(true)
        {
            if(pq.size() == 0)
            {
                return 0;
            }
            else if (pq.size() == 1)
            {
                return pq.top();
            }
            else
            {
                int first = pq.top();
                pq.pop();
                int second = pq.top();
                pq.pop();

                if(first == second)
                    continue;
                else
                    pq.push(first - second);
            }
        }
    }
};
