//2 equal subset sum means s1+s2 = s but s1=s2 => s1 =>s/2;
//hence the problem boils down to finding a subset whose target = s/2. if s is odd then we can't have any such subset hence return false

//RECURSION
// class Solution {
// public:
//     bool f(int i, vector<int>arr, int sum){
//         if(sum == 0)
//             return true;
//         if(i == 0)
//             return (arr[i] == sum);
//         bool nottake = f(i-1,arr,sum);
//         bool take = false;
//         if(sum >= arr[i])
//             take = f(i-1,arr,sum-arr[i]);
//         return take || nottake;
//     }
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         for(int i=0; i<n; i++){
//             sum += nums[i];
//         }
//         if(sum%2 != 0)
//             return false;
//         return f(n-1,nums,sum/2);
//     }
// };

//MEMOIZATION
// class Solution {
// public:
//     bool f(int i, vector<int>arr, int sum, vector<vector<int>> dp){
//         if(sum == 0)
//             return true;
//         if(i == 0)
//             return (arr[i] == sum);
//         if(dp[i][sum] != -1)
//             return dp[i][sum];
//         bool nottake = f(i-1,arr,sum,dp);
//         bool take = false;
//         if(sum >= arr[i])
//             take = f(i-1,arr,sum-arr[i],dp);
//         return dp[i][sum] = take || nottake;
//     }
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         for(int i=0; i<n; i++){
//             sum += nums[i];
//         }
//         if(sum%2 != 0)
//             return false;
//         vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));
//         return f(n-1,nums,sum/2,dp);
//     }
// };


//TABULATION
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if(sum%2 != 0)
            return false;

        int k = sum/2;
        vector<vector<bool>> dp(n,vector<bool>(k+1,false)); 

        for(int i=0; i<n; i++){
            dp[i][0] = true;   
        }
        if(nums[0]<=k)
            dp[0][nums[0]] = true;

        for(int i=1; i<n; i++){
            for(int j=1; j<=k; j++){
                bool nottake = dp[i-1][j];
                bool take = false;
                if(j >= nums[i])
                    take = dp[i-1][j-nums[i]];
                dp[i][j] = take || nottake;                
            }
        }
        return dp[n-1][k];
    }
};