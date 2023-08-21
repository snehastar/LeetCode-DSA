//TABULATION
//refer to longest common subseuence and longest palindromic subsequence to arrive at this solution
//eg: leetcode
//note that in this question we can nsert element at any index
//find the longest plaindromic subsequence ->eee
//to make this word a palindrome 
//we add the rest of the letters in reverse order to make it a palindrome
// let's capitalise the palindromic part
// lEEtcodE
//  EE    E
//adding reversed non palindromic subsequence part in reverse in opposite index
//  E   E    E
// assume palindrome to be as E mid element E
// lE   E    El 
// lEdoctEtcodEl
// therefore the number of elements we added is number of elements in the string - length of longest palindromic subsequence
class Solution {
public:
    int minInsertions(string s) {
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
        int num = dp[n][n]; 
        int ans = n-num;
        return ans;
    }
};