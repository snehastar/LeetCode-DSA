class Solution {
public:
int f(int i, int status, vector<int>& prices, vector<vector<int>> &dp){
        if(i >= prices.size())
            return 0;
            
        int profit = 0;

        if(dp[i][status] != -1)
            return dp[i][status];

        if(status == 1) //buy
            profit =  max(-prices[i] + f(i+1,0,prices,dp), f(i+1,1,prices,dp));
        else if(status == 0) //sell
            profit = max(prices[i] + f(i+2,1,prices,dp), f(i+1,0,prices,dp));
        return dp[i][status] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1)
            return 0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,1,prices,dp);        
    }
    
};