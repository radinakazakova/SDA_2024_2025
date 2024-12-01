//не минава всички тестове
#include <bits/stdc++.h>

using namespace std;

int main() {
    string first, second;
    cin >> first >> second;
    size_t M = first.size(), N = second.size();

    size_t maxSequence = 0;
    for (size_t row = 0, currentRow = 0; row < M; ++row, ++currentRow) {
        size_t sequence = 0;
        for (size_t column = 0; column < N && currentRow < M; ++column) {
            if (first[currentRow++] != second[column]) {
                sequence = 0;
            } else {
                sequence++;
                maxSequence = max(maxSequence, sequence);
            }
        }
    }

    cout << maxSequence;
}

//същото решение само че с динамично програмиране

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    size_t M = s1.size();
    size_t N = s2.size();

    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    int maxLen = 0;

    for (size_t i = 1; i <= M; ++i) 
    {
        for (size_t j = 1; j <= N; ++j) 
        {
            if (s1[i - 1] == s2[j - 1]) 
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }

    cout << maxLen;
    return 0;
}
