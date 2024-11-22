class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount + 1, INT_MAX);
        dp[0] = 0; //база за 0 лева - 0 монети
        
        // i is current value
        for(int i = 1; i <= amount; i++) { //за всяка монета
            for (int coin : coins) { //и за всеки вид монета с който разполагаме
                if (i >= coin && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1); //минимума между каквото сме получили до сега или изпробваното с новата монета (за нея колко монети са нужни + 1)
                }
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
