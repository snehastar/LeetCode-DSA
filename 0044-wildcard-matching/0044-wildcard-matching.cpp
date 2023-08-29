//recursion
    // bool f(int i, int j, string &s, string &p){
    //     //base case
    //     if(i<0 && j<0)
    //         return true;
    //     if(i<0 && j>=0)
    //         return true;
    //     if(i>=0 && j<0){
    //         for(int k = i; k>=0; k--){
    //             if(s[k] != '*')
    //                 return false;
    //         }
    //         return true;
    //     }

    //     //recurrence
    //     if(s[i] == p[j] || p[j] == '?'){
    //         return f(i-1, j-1, s, p);
    //     }
    //     if(p[j] == '*'){
    //         return f(i-1, j, s, p) || f(i, j-1, s, p);
    //     }

    //     return false;
    // }
    // bool isMatch(string s, string p) {
    //     int n1 = s.size();
    //     int n2 = p.size();
    //     return f(n1-1, n2-1, s, p);
    // }
class Solution {
public:
//memoization
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        //base case
        if(i<0 && j<0)
            return 1;
        if(i>=0 && j<0)
            return 0;
        if(i<0 && j>=0){
            for(int k = 0; k<=j; k++){
                if(p[k] != '*')
                    return 0;
            }
            return 1;
        }

        if(dp[i][j] != -1)
                return dp[i][j];
                
        //recurrence
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = f(i-1, j-1, s, p, dp);
        }
        if(p[j] == '*'){
            return dp[i][j] = f(i-1, j, s, p, dp) || f(i, j-1, s, p, dp);
        }

        return 0;
    }
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<int>> dp(n1, vector<int> (n2,-1));
        return f(n1-1, n2-1, s, p, dp);
    }
};