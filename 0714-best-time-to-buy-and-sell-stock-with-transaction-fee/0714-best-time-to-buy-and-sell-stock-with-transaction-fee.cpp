class Solution {
public:
//memoization
// int f(int i, int status, vector<int>& prices, vector<vector<int>> &dp, int fee){
//         if(i >= prices.size())
//             return 0;
            
//         int profit = 0;

//         if(dp[i][status] != -1)
//             return dp[i][status];

//         if(status == 1) //buy
//             profit =  max(-prices[i] + f(i+1,0,prices,dp,fee), f(i+1,1,prices,dp,fee));
//         else if(status == 0) //sell
//             profit = max(prices[i] - fee + f(i+1,1,prices,dp,fee), f(i+1,0,prices,dp,fee));
//         return dp[i][status] = profit;
//     }
//tabulation
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n<=1)
            return 0;
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1; i>=0; i--){
            for(int status = 0; status <=1; status ++){
                int profit = 0;

                if(status == 1) //buy
                    profit = max(-prices[i] + dp[i+1][0],dp[i+1][1]);           
                else if(status == 0) //sell
                    profit = max(prices[i] - fee + dp[i+1][1],dp[i+1][0]);
                dp[i][status] = profit;    
            }
        }
        return dp[0][1];  
    }
};