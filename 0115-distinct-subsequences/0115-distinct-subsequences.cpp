//RECURSIVE
// int f(int i, int j,string s, string t){
//         //base case
//         if(j<0)
//             return 1;

//         if(i<0){
//             return 0;
//         }

//         if(s[i] == t[j]) //match
//            return  f(i-1,j-1,s,t) + f(i-1,j,s,t);
//         else //not a match
//            return f(i-1,j,s,t);
//     }
//     int numDistinct(string s, string t) {
//         int n1 = s.size();
//         int n2 = t.size();
//         return f(n1,n2,s,t);
//     }
class Solution {
public:
//Memoization
    int f(int i, int j,string s, string t,vector<vector<int>> &dp){
        //base case
        if(j<0)
            return 1;

        if(i<0){
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == t[j]) //match
           return  dp[i][j] = f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp);
        else //not a match
           return dp[i][j] = f(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1,-1));
        return f(n1,n2,s,t,dp);
    }
};