//not in-place solution
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) { //Редовете стават колони, но в обратен ред
        int n = matrix.size();
        //Гледаме input и output - виждаме, че наредбата е
        //от последна редица към първа при съответния индекс последователно
      //input : [[1,2,3],[4,5,6],[7,8,9]]
      //output: [[7,4,1],[8,5,2],[9,6,3]]

        vector<vector<int>> rotated;
        for(int i = 0; i < n; ++i) {
             rotated.push_back(vector<int>{});
        }

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 0; j< n; j++)
            {
                rotated[j].push_back(matrix[i][j]);
            }
        }

        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                matrix[i][j] = rotated[i][j];
            }
        }

    }
};
