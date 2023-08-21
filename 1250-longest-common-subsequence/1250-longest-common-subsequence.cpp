//MEMOIZATION
// int f(int i1, int i2, string &text1, string &text2, vector<vector<int>> &dp){

//         if(i1<0 || i2<0)
//             return 0;
//         if(dp[i1][i2] != -1)
//             return dp[i1][i2];
//         //match
//         if(text1[i1] == text2[i2])
//             return dp[i1][i2] = 1 + f(i1-1, i2-1, text1, text2,dp);
//         else //notmatch
//             return dp[i1][i2] = max(f(i1-1, i2, text1, text2,dp), 
//         f(i1, i2-1, text1, text2,dp));

//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int n1 = text1.size();
//         int n2 = text2.size();
//         vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));
//         return f(n1-1,n2-1,text1,text2,dp);    
//     }
class Solution {
public:
//TABULATION
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));
        //here to make base case i1<0 and i2<0  we can't store it in dp array
        //hence we shift the array by one index to store the value of -1 at 0 index, 0 at 1st index
        //here i<=n2 not i<n2 because we store the element till n2 because of shift of index by 1 step
        for(int i=0; i<=n2; i++){
            dp[0][i] = 0;
        }
        for(int i=0; i<=n1; i++){
            dp[i][0] = 0;
        }

        for(int i1=1; i1<=n1; i1++){
            for(int i2=1; i2<=n2; i2++){
                if(text1[i1-1] == text2[i2-1])//left shift of index
                    dp[i1][i2] = 1 + dp[i1-1][i2-1];
                else //notmatch
                    dp[i1][i2] = max(dp[i1-1][i2],dp[i1][i2-1]);    
            }
        }   
        return dp[n1][n2];    
    }
};