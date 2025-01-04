struct HelperForSorting
{
    string vid;
    int count;

    bool operator<(const HelperForSorting& other)const
    {
        if(count == other.count)
        {
            return vid < other.vid;
        }
        return count < other.count;
    }
};
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int size = friends.size();
        int currLevel = 0;
        vector<bool> visited(size, false);
        queue<int> q;
        q.push(id);
        visited[id] = true; 

        // BFS to find friends at the target level
        while (!q.empty() && currLevel < level) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                int curr = q.front();
                q.pop();
                for (auto& f : friends[curr]) {
                    if (!visited[f]) {
                        visited[f] = true;
                        q.push(f);
                    }
                }
            }
            currLevel++;
        }

        // If the desired level hasn't been reached
        if (currLevel != level) {
            return {};
        }

        unordered_map<string, int> videos;
        vector<string> res;
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            for(const auto& vid: watchedVideos[curr])
            {
                videos[vid]++;
            }
        }
        vector<HelperForSorting> temp;
        for(const auto& [vid, count]: videos)
        {
            temp.push_back({vid, count});
        }

        sort(temp.begin(), temp.end());

        for(const auto& [vid,_]: temp)
        {
            res.push_back(vid);
        }

        return res;
    }
};
