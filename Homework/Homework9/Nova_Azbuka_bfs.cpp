#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

pair<char, char> compareString(const string& str1, const string& str2) {
    size_t minLength = min(str1.size(), str2.size());
    for (size_t i = 0; i < minLength; i++) {
        if (str1[i] != str2[i]) {
            return {str1[i], str2[i]};
        }
    }
    return {'\0', '\0'};
}

string findAlphabetOrder(const vector<string>& words) {
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, int> inDegree;

    for (const string& word : words) {
        for (char ch : word) {
            if (!inDegree.count(ch)) {
                inDegree[ch] = 0;
            }
        }
    }

    for (size_t i = 0; i < words.size() - 1; i++) {
        pair<char, char> diff = compareString(words[i], words[i + 1]);
        if (diff.first != '\0') 
        {
          //ако не сме добавили новонамереното ребро, добавяме го
            if (!graph[diff.first].count(diff.second)) 
            {
                graph[diff.first].insert(diff.second);
              //съответно отбелязваме, че имаме ребро, влизащо във втория възел
                inDegree[diff.second]++;
            }
        }
    }
  
    queue<char> q;
    for (auto& [node, degree] : inDegree) {
        if (degree == 0) { //за тези, в които никой не влиза, трябва да ги добавим в опашката 
            q.push(node);
        }
    }

    string result;
    while (!q.empty()) {
        char current = q.front();
        q.pop();
        result += current;

        for (char neighbor : graph[current]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return result.size() == inDegree.size() ? result : "";
}

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    auto order = findAlphabetOrder(words);
    
    for(size_t i = 0; i < order.size(); i++)
    {
        cout << order[i] << " ";
    }

    return 0;
}
