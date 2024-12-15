//подобно на решението с оцветяването
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        // u - unopened
        // o - opened - за проверка за цикъл
        // c - closed - посетен
        vector<char> visited(numCourses, 'u');

        for(const auto& req: prerequisites) {
            graph[req[0]].push_back(req[1]); //в такава последователност, защото стигаме първо до дъното и се връщаме - редът ще е правилен от beginner към advanced
        }

        vector<int> result;
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 'u') {
                if(!dfs(graph, visited, result, i)) {
                    return vector<int>();
                }
            }
        }

        return result;
    }

    bool dfs(const vector<vector<int>>& graph, vector<char>& visited, vector<int>& result, int current){
        if(visited[current] == 'c'){
            return true;
        }

        if(visited[current] == 'o'){ 
            return false;
        }

        visited[current] = 'o';

        for(const auto& node: graph[current]){
            if(!dfs(graph, visited, result, node)) {
                return false;
            }
        }

        result.push_back(current);
        visited[current] = 'c';

        return true;
    }
};
