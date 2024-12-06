class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {    
        
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first; 
        };

        std::priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq;

        int size = points.size();

        for(int i = 0; i < size; i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            int dist = x*x + y*y;
            pq.push({dist, i});
        }

        vector<vector<int>> res;
        while(k)
        {
            auto curr = pq.top();
            pq.pop();
            res.push_back(points[curr.second]);
            k--;
        }

        return res;
    }
};
