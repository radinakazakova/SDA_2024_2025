
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int roadsCount = specialRoads.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // (дистанция, индекс на специалния път)
        vector<int> distances(roadsCount, INT_MAX);

        for(int i = 0; i < roadsCount; i++) //добавяме само специалните пътища в опашката, защото е ясно как ще стигнем до тях, за да ги пробваме
        {
            distances[i] = abs(start[0] - specialRoads[i][0]) + abs(start[1] - specialRoads[i][1]) + specialRoads[i][4];
            pq.push({distances[i], i});
        }

        int ans = abs(start[0] - target[0]) + abs(start[1] - target[1]); //временен отговор е направо от старт да отидем до таргет

        while(!pq.empty())
        {
            auto [dist, index] = pq.top();
            pq.pop();

            if(dist > distances[index])
            {
                continue;
            }

            ans = min(ans, dist + abs(target[0] - specialRoads[index][2]) + abs(target[1] - specialRoads[index][3])); //от края на специалния път пробваме да отидем до таргет

            for(int next = 0; next < roadsCount; next++) //от края на един специален път да стигнем до началото и края на друг
            {
                int newDist = abs(specialRoads[index][2] - specialRoads[next][0]) + abs(specialRoads[index][3] - specialRoads[next][1]) + specialRoads[next][4];

                if(dist + newDist < distances[next])
                {
                    distances[next] = dist + newDist;
                    pq.push({distances[next], next});
                }
            }
        }
        return ans;
    }
};
