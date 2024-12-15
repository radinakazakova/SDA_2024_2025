class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //center will be present in every edge from edges
        unordered_map<int, int> seen; //vertex and count of occurences
        for(auto edge: edges)
        {            
            if(seen[edge[0]] == 1)
                return edge[0];
            if(seen[edge[1]] == 1)
                return edge[1];

            seen[edge[0]]++;
            seen[edge[1]]++; 
        }
        return -1;
    }
};
