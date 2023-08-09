class Solution {
public:
//RECURSION
// tc: O(2^n) sc:O(2n)
    //    int f(int n,vector<int>& nums){
    //     if(n == 0)
    //         return nums[0];
    //     if(n < 0)
    //         return 0;
    //     int pick = nums[n] + f(n-2, nums);
    //     int notpick = 0 + f(n-1, nums);

    //     return max(pick, notpick);
    // }
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     return f(n-1,nums);        
    // } 

//MEMOIZATION
// tc: O(n) sc:O(2n)
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
// tc: O(n) sc:O(n)
    // int f(int n,vector<int>& nums, vector<int> dp){
    //     dp[0] = nums[0]; 
    //     for(int i=1; i<n; i++){
    //         int pick = nums[i];
    //         if(i>1)
    //             pick += dp[i-2];
    //         int notpick = 0 + dp[i-1];
    //         dp[i] = max(pick,notpick);
    //     }
    //     return dp[n-1];
    // }
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n,-1); 
    //     return f(n,nums, dp);        
    // }

//SPACE OPTIMIZATION
// tc: O(n) sc:O(1)
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        int prev = nums[0]; 
        int prev2 = 0;
        for(int i=1; i<n; i++){
            int pick = nums[i] + prev2;
            int notpick = 0 + prev;
            int curr = max(pick,notpick);
            
            prev2 = prev;
            prev = curr;
            
        }
        return prev;
    }
};