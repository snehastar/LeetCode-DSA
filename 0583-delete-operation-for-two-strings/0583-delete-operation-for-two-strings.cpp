//TABULATION
//REFER TO LONGEST SUBSEQUENCE IN TWO STRINGS
//we find the length of common longest subsequence
//no of different alphabets are the minimum number of steps required to be deleted as the rest of the subsequence will match
//return sum of length of two strings - 2*countoflongestcommomsubsequence
// return n1+n2-(2*count)
//eg: sea eat, LCS = ea => count = 2
//return 3+3-(2*2) = 2
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        int count = dp[n1][n2];
        //cout<<num<<endl;
        int ans = n1+n2-(2*count);
        return ans;    
    }
};