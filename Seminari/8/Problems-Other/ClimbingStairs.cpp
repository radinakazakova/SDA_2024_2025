class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) { //baza
            return 1;
        }

        vector<int> dp(n+1); //za nulata + 1
        dp[0] = dp[1] = 1; 
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2]; //за всяко стъпало е изпълнено, че може да се стигне до него по начините, по които може да се стигне до предходните две събрани
        }
        return dp[n];
    }
};
