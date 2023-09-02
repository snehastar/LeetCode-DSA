class Solution {
public:
int f(int i, int status,int k, vector<int>& prices, vector<vector<vector <int>>> &dp){     
    if(i == prices.size())
        return 0;
        if(k == 0){
            return 0;   
        } 
        int profit = 0;

               

        if(dp[i][status][k] != -1)
            return dp[i][status][k];

        if(status == 1) //buy
            profit =  max(-prices[i] + f(i+1,0,k,prices,dp), f(i+1,1,k,prices,dp));
        else if(status == 0) //sell
            profit = max(prices[i] + f(i+1,1,k-1,prices,dp), f(i+1,0,k,prices,dp));
        return dp[i][status][k] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n<=1)
            return 0;
       
        vector<vector<vector<int>>> dp(n,
        vector<vector<int>>(2,
        vector<int>(k+1,-1)));
        return f(0,1,k,prices,dp);     
    }
};