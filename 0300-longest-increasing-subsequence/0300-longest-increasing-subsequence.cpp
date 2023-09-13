//Recursive
    // int f(int i,int prev, vector<int> &nums){
    //     if(i==nums.size())
    //         return 0;
    //     int pick = 0;
    //     int notpick = 0;
    //     if(prev == -1 ||nums[i]>nums[prev])
    //         pick = 1 + f(i+1,i,nums);
        
    //     notpick = f(i+1,prev,nums);
    //     return max(pick, notpick);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n<=1)
    //         return n;
    //     return f(0,-1,nums);    
    // }
class Solution {
public:
//memoization
    // int f(int i,int prev, vector<int> &nums, vector<vector<int>> dp){
    //     if(i==nums.size())
    //         return 0;
    //     int pick = 0;
    //     int notpick = 0;
    //     if(dp[i][prev+1] != -1)
    //         return dp[i][prev+1];
    //     if(prev == -1 ||nums[i]>nums[prev])
    //         pick = 1 + f(i+1,i,nums,dp);
        
    //     notpick = f(i+1,prev,nums,dp);
    //     return dp[i][prev+1] = max(pick, notpick);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n<=1)
    //         return n;
    //     vector<vector<int>> dp(n,vector<int>(n+1,-1));
    //     return f(0,-1,nums,dp);    
    // }
    //tabulation

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)
            return n;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1; i>=0; i--){
            for(int prev = i-1; prev >=-1; prev--){
                int pick = 0;
                int notpick = 0;
                if(prev == -1 || nums[i]>nums[prev])
                    pick = 1 + dp[i+1][i+1];
                notpick = dp[i+1][prev+1];
                dp[i][prev+1] = max(pick, notpick);    
            }
        }
        return dp[0][0];    
    }
};