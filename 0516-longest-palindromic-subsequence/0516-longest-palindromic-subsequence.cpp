//TABULATION DIRECTLY USED HERE
//refer to find longest common subsequence in 2 strings
// here we create a verse of a string as the second string and apply the same logic
//because plaindrome means the two strings will match after reversal, hence we use another string
//brute force will be to generate all subsequences and check which among them is a palindrome and also find the max length among them
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string q = s;
        reverse(q.begin(), q.end());
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == q[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];        
    }
};