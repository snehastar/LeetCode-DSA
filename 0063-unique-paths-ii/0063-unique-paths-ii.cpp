//RECURSIVE
//TC: O(2^(N*M))
//SC: O(N-1) + O(M-1) //PATH LENGTH
/*class Solution {
public:

    int f(int i, int j, vector<vector<int>>& obstacleGrid){
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0 || obstacleGrid[i][j] == 1 )
            return 0;
        int l = f(i-1,j, obstacleGrid);
        int r = f(i,j-1, obstacleGrid);

        return l+r;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1)
            return 0;
        int ans = f(m-1,n-1,obstacleGrid);
        return ans;    
    }
};
*/

//DP MEMOIZATION
//TC: O(N*M)
//SC: O(N-1)+O(M-1) + O(N*M) //STACK SPACE AND DP ARRAY
class Solution {
public:

    int f(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0 || obstacleGrid[i][j] == 1 )
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int l = f(i-1,j, obstacleGrid, dp);
        int r = f(i,j-1, obstacleGrid, dp);

        return dp[i][j] = l+r;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1)
            return 0;
        int ans = f(m-1,n-1,obstacleGrid,dp);
        return ans;    
    }
};