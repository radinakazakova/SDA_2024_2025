class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        std::priority_queue<pair<int,int>, vector<pair<int,int>>, decltype( [](const pair<int,int>& lhs, const pair<int,int>& rhs) 
        {
            return lhs.first < rhs.first;
        })> pq;

        int size = score.size();

        for(int i = 0; i< size; i++)
        {
            pq.push({score[i], i});
        }

        vector<string> res(size);
        for(int i = 0; i < size; i++)
        {
            auto curr = pq.top();
            pq.pop();
            if(i == 0)
            {
                res[curr.second] = "Gold Medal";
            }
            else if(i==1)
            {
                res[curr.second] = "Silver Medal";
            }
            else if(i == 2)
            {
                res[curr.second] = "Bronze Medal";
            }
            else
            {
                res[curr.second] = to_string(i+1);
            }
        }
        return res;
    }
};
