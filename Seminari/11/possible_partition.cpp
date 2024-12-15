class Solution {
    // mark every node with color
    // we can use only two colors for separation => red and blue => boolean true/false (двете групички)
    bool dfs(int current, unordered_map<int, unordered_set<int>>& graph, unordered_map<int, bool>& colors, bool currentColor = true) {
      //ако вече е оцветено, проверяваме дали цвета отговаря на цвета, който искаме то да бъде сега (ако не съвпада, не можем да ги разделим на две)
        auto iter = colors.find(current);
        if(iter != colors.end()) {
            return iter->second == currentColor;
        } 
        
        colors[current] = currentColor;
        //тъй като възлите са свързани по критерий dislike - като обхождаме съседите, ще им подаваме другия цвят, за да не са в една група
        for(auto& neighbour: graph[current]) {
            if(!dfs(neighbour, graph, colors, !currentColor)) {
                return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, unordered_set<int>> graph;
        for(auto& edge: dislikes) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        unordered_map<int, bool> colors;
        for(auto& kvp: graph) {
            auto iter = colors.find(kvp.first);
            if(iter == colors.end()) {
                if(!dfs(kvp.first, graph, colors)) {
                    return false;
                }
            }
        }
        return true;
    }
};
