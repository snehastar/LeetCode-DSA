class Solution {
public:
    int f(int amount, vector<int>& coins, int i, vector<vector<int>> &dp){
        if(i == 0){
            if(amount%coins[0] == 0)
                return 1;
            return 0;
        }
        if(amount == 0)
            return 1;
        if(dp[i][amount] != -1)
            return dp[i][amount];
        int nottake = f(amount, coins, i-1,dp);
        int take = 0;
        if(amount >= coins[i])
            take = f(amount-coins[i], coins, i,dp);
        return dp[i][amount]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1,-1));
        return f(amount, coins, n-1,dp);    
    }
};