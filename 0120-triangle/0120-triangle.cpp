class Solution {
public:
//RECURSIVE
//TC: O(2^((N*M)/2))
//SC: O(N*M/2)
    int f(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        if(i == n){
            return triangle[i][j];
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        int d = triangle[i][j] + f(i+1,j,n,triangle, dp);
        int rd = triangle[i][j] + f(i+1,j+1,n,triangle, dp);
        return dp[i][j] = min(d,rd);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,n-1,triangle,dp);
    }
};