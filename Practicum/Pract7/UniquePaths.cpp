class Solution {
public:
    int uniquePaths(int m, int n) {
        int cols = n;
        int rows = m;

        vector<long long> level(cols, 0);

        for(int i = 0; i < cols; i++) //определяме първия ред
        {
            level[i] = 1;
        }
        
        for(int i = 1; i < rows; i++) 
        {
            for(int j = 1; j < cols; j++) 
            {
                level[j] += level[j - 1];
            }
        }
        
        return level[cols - 1];
    }
};
