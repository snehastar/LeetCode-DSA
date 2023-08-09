class Solution {
public:
//MEMOIZATION
    // int f(int i,vector<int>& nums, vector<int> &dp){
        
    //     if(i == 0)
    //         return nums[i];
    //     if(i < 0)
    //         return 0;
    //     if(dp[i] != -1)
    //         return dp[i];
    //     int pick = f(i-2,nums,dp) + nums[i];
    //     int notpick = f(i-1,nums,dp);
    //     return dp[i] = max(pick,notpick);
    // }

    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n,-1);
    //     int sum = f(n-1,nums,dp);
    //     return sum;    
    // }

//TABULATION
    int f(int n,vector<int>& nums, vector<int> dp){
        dp[0] = nums[0]; 
        for(int i=1; i<n; i++){
            int pick = nums[i];
            if(i>1)
                pick += dp[i-2];
            int notpick = 0 + dp[i-1];
            dp[i] = max(pick,notpick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1); 
        return f(n,nums, dp);        
    }
};