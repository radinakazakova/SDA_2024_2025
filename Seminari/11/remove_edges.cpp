#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

size_t result = 0;

//result ни преброява колко компонента ще имаме като махнем ребрата
//ребрата, които сме махнали са result - 1 на брой

size_t dfs(vector<unordered_set<size_t>>& graph, unordered_set<size_t>& visited, size_t current){
    if(graph[current].size() == 0){
        return 1;
    } 
    
    visited.insert(current);
    
    size_t children = 1; //всеки node знае колко node-a има в текущия му компонент (по обхождане)
    for(auto& val: graph[current]) {
        if(!visited.count(val)){
            children += dfs(graph, visited, val);
        }
    }

  //възможно най-надолу в рекурсията, където намерим четен брой компоненти, ги разделяме от останалите, като не им добавим броя към node-a, от който сме дошли
    if(children % 2 == 0){
        result++;
        return 0;
    }
    
    return children;
}

int main() {
    size_t nodesCount, edgesCount;
    std::cin >> nodesCount >> edgesCount;
    
    vector<unordered_set<size_t>> graph(nodesCount + 1);
    
    for(size_t i = 0; i < nodesCount; i++){
        size_t first, second;
        cin >> first >> second;
        graph[first].insert(second);
        graph[second].insert(first);
    }
    
    unordered_set<size_t> visited;
    dfs(graph, visited, 1);
    
    std::cout << result - 1;
}
