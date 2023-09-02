class Solution {
public:
int f(int i, int status,int cap, vector<int>& prices, vector<vector<vector <int>>> &dp){     
    if(i == prices.size())
        return 0;
        if(cap == 0){
            return 0;   
        } 
        int profit = 0;

               

        if(dp[i][status][cap] != -1)
            return dp[i][status][cap];

        if(status == 1) //buy
            profit =  max(-prices[i] + f(i+1,0,cap,prices,dp), f(i+1,1,cap,prices,dp));
        else if(status == 0) //sell
            profit = max(prices[i] + f(i+1,1,cap-1,prices,dp), f(i+1,0,cap,prices,dp));
        return dp[i][status][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1)
            return 0;
       
        vector<vector<vector<int>>> dp(n,
        vector<vector<int>>(2,
        vector<int>(3,-1)));
        return f(0,1,2,prices,dp);        
    }
};