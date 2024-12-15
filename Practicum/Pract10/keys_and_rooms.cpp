class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int room, vector<bool>& visited)
    {
        visited[room] = true;
      //посещаваме всяка стая, която можем и не сме посещавали до сега
        for(auto& r: rooms[room])
        {
            if(!visited[r])
                dfs(rooms, r, visited);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, 0, visited);
        
        for(bool v: visited)
        {
          //ако има стая, която е останала непосетена - false
            if(!v)
                return false;
        }
        return true;
    }
};
