class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size();
        int size2 = text2.size();

        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

        for(int i = 0; i< size1; i++)
        {
            for(int j = 0; j < size2; j++)
            {
                if(text1[i] == text2[j]) //ако се припокриват, ъндейтваме за следващата буква - по диагонал
                {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
                else
                {
                    dp[i + 1][j + 1] = max(dp[i][j+1],dp[i+1][j]); //не се припокриват - имаме два избора за буква от първата дума или от втората - тоест търсим макса на sequence-a който е по-висок в една от двете думи
                }
            }
        }
        return dp[size1][size2];
    }
};
