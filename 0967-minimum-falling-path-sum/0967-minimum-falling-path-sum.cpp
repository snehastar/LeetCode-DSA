//RECURSIVE
//TC: O(2^((N*M)/2))
//SC: O(N*M) + O(N)+O(N)
// class Solution {
// public:
//     int f(int i, int j, int n, vector<vector<int>>& matrix){ 
        
//         if( j<0 || j>n )
//             return 1e9;
            
//         if(i == 0)
//             return matrix[0][j];
        
//         int u = matrix[i][j] + f(i-1,j,n,matrix);
//         int ur = matrix[i][j] + f(i-1,j+1,n,matrix);
//         int ul = matrix[i][j] + f(i-1,j-1,n,matrix);
//         return min(u,min(ur,ul));
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         //vector<vector<int>> dp(n,vector<int>(m,-1));
//         int ans = 1e9;
//         for(int k = n-1; k>=0; k--){
//             ans = min(ans,f(n-1,k,n-1,matrix));
//         }
//         return ans;  
//     }
// };

//MEMOIZATION
//TC: O(N*M)
//SC: O(N*M) + O(N)+O(N)
// class Solution {
// public:
//     int f(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>> &dp){ 
        
//         if( j<0 || j>n )
//             return 1e9;
            
//         if(i == 0)
//             return matrix[0][j];
//         if(dp[i][j] != -1)
//             return dp[i][j];

//         int u = matrix[i][j] + f(i-1,j,n,matrix,dp);
//         int ur = matrix[i][j] + f(i-1,j+1,n,matrix,dp);
//         int ul = matrix[i][j] + f(i-1,j-1,n,matrix,dp);
//         return dp[i][j] = min(u,min(ur,ul));
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         int ans = 1e9;
//         for(int k = n-1; k>=0; k--){
//             ans = min(ans,f(n-1,k,n-1,matrix,dp));
//         }
//         return ans;  
//     }
// };

//TABULATION
//TC: O(N*M)
//SC: O(N)+O(N)
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>> dp(n,vector<int>(n,0));
//         int ans = 1e9;

//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                     if(i == 0){
//                         dp[i][j] = matrix[i][j];
//                         continue;
//                     }
//                     int u = 1e9;
//                     int ur = 1e9;
//                     int ul = 1e9;
//                     if(i>0 && j>0)
//                         ul = matrix[i][j] + dp[i-1][j-1];
//                     if(i>0 && j<n-1)
//                         ur = matrix[i][j] + dp[i-1][j+1];
//                     if(i>0)
//                         u = matrix[i][j] + dp[i-1][j];                    
//                     dp[i][j] = min(u,min(ur,ul));        
//             }
//         }
//         int mini = 1e9;
//         for(int i=0; i<n; i++){
//             mini = min(mini,dp[n-1][i]);
//         }
//         return mini;  
//     }
// };

//SPACE OPTIMIZATION
//TC: O(N*M)
//SC: O(N)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n,0);
        int ans = 1e9;

        for(int i=0; i<n; i++){
            vector<int> temp(n,0);
            for(int j=0; j<n; j++){
                    if(i == 0){
                        temp[j] = matrix[i][j];
                        continue;
                    }
                    int u = 1e9;
                    int ur = 1e9;
                    int ul = 1e9;
                    if(i>0 && j>0)
                        ul = matrix[i][j] + prev[j-1];
                    if(i>0 && j<n-1)
                        ur = matrix[i][j] + prev[j+1];
                    if(i>0)
                        u = matrix[i][j] + prev[j];                    
                    temp[j] = min(u,min(ur,ul));        
            }
            prev = temp;
        }
        int mini = 1e9;
        for(int i=0; i<n; i++){
            mini = min(mini,prev[i]);
        }
        return mini;  
    }
};