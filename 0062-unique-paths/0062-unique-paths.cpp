/*
    int uniquePaths(int m, int n) {
        //assuming we have a 3*4 grid, we need to go 3 steps downwards, Let's say it DDD, and 4 steps right, Say RRRR.
//so if we find the number of ways to rearrange the string DDDRRRR, we get the ans. Which is (m+n)!/m!n! 

        int N = n+m-2; // total steps = n-1 + m-1
        int r = m - 1; 
        double ans = 1;
        //compute nCr don't take i as 0 because we divide by i
        //9C3 = 9*8*7/3*2*1
        for(int i=1; i<=r; i++){
            ans = ans * (N-r+i) / i;
        }
        
        return (int)ans;
   }
*/

//RECURSIVE TC:O(2^(n*m)) SC: O(path length) = O(n-1)+O(m-1)
/*class Solution {
public:
    
    int f(int i, int j){
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0)
            return 0;
        int l = f(i-1,j);
        int r = f(i,j-1);

        return l+r;
    }

    int uniquePaths(int m, int n) {
        int ans = f(m-1,n-1);
        return ans;    
    }
};*/

//MEMOIZATION
//TC: O(n*m)
//SC: O(n-1)+O(m-1) + O(m*n) //stack space and dp array
class Solution {
public:
    
    int f(int i, int j, vector<vector<int>> &dp){
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int l = f(i-1, j, dp);
        int r = f(i, j-1, dp);

        return dp[i][j] = l+r;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        int ans = f(m-1, n-1, dp);
        return ans;    
    }
};