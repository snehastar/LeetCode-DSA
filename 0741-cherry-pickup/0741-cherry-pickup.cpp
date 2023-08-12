//RECURSIVE
//TC: O(N^4)
//SC: stack space
// class Solution {
// public:
   
//     int f(int i1, int j1,int i2, int j2, int n, vector<vector<int>>& grid){
//         if(i1==n && j1==n){//base case
//             return grid[i1][j1];//count only once
//         }
//         int cherries = 0;
//         if(i1>n || j1>n || i2>n || j2>n || grid[i1][j1] == -1 || grid[i2][j2] == -1)
//             return -1e8;
//         if(i1==i2 && j1==j2){
//             cherries+=grid[i1][j1];
//         }
//         else{
//             cherries+=grid[i1][j1]+grid[i2][j2];
//         }
//         int dd = f(i1+1,j1,i2+1,j2,n,grid);
//         int dr = f(i1+1,j1,i2,j2+1,n,grid);
//         int rd = f(i1,j1+1,i2+1,j2,n,grid);
//         int rr = f(i1,j1+1,i2,j2+1,n,grid);
//         int maxi = max(max(dd,dr),max(rd,rr));
//         return maxi+cherries;
//     }

//     int cherryPickup(vector<vector<int>>& grid) {
//         int n = grid.size();
//         if(grid[0][0] == -1 || grid[n-1][n-1] == -1)
//             return 0;
//         int maxi = 0;        
//         return max(maxi,f(0,0,0,0,n-1,grid));
//     }
// };

//MEMOIZATION
//TC: O(N^4)
//SC: O(N^4)
class Solution {
public:
  
    int f(int i1, int j1,int i2, int j2, int n, vector<vector<int>>& grid, vector<vector<vector<vector<int>>>> &dp){
        if(i1==n && j1==n){//base case
            return grid[i1][j1];//count only once
        }
        int cherries = 0;
        if(i1>n || j1>n || i2>n || j2>n || grid[i1][j1] == -1 || grid[i2][j2] == -1)
            return -1e8;

        if(dp[i1][j1][i2][j2] != -2)
            return dp[i1][j1][i2][j2];
        if(i1==i2 && j1==j2){
            cherries+=grid[i1][j1];
        }
        else{
            cherries+=grid[i1][j1]+grid[i2][j2];
        }
        int dd = f(i1+1,j1,i2+1,j2,n,grid,dp);
        int dr = f(i1+1,j1,i2,j2+1,n,grid,dp);
        int rd = f(i1,j1+1,i2+1,j2,n,grid,dp);
        int rr = f(i1,j1+1,i2,j2+1,n,grid,dp);
        int maxi = max(max(dd,dr),max(rd,rr));
        return dp[i1][j1][i2][j2] = maxi+cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == -1 || grid[n-1][n-1] == -2)
            return 0;
        int maxi = 0; 
        
        vector<vector<vector<vector<int>>>> dp(n,
        vector<vector<vector<int>>> (n,
        vector<vector<int>> (n,
        vector<int>(n,-2))));   
        return max(maxi,f(0,0,0,0,n-1,grid,dp));
    }
};