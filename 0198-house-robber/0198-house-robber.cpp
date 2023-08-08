class Solution {
public:
    int f(int i,vector<int>& nums, vector<int> &dp){
        //MEMOIZATION
        if(i == 0)
            return nums[i];
        if(i < 0)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int l = f(i-2,nums,dp) + nums[i];
        int r = f(i-1,nums,dp);
        return dp[i] = max(l,r);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        int sum = f(n-1,nums,dp);
        return sum;    
    }
};