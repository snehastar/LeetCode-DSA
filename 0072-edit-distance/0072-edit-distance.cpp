//RECURSIVE
//we start from back
//if character matches we move both i and i back
//if not matching means we have 3 options
//we hypothetically perform these operations and add 1 for these operations
//1. delete character: horse ros , s and e not matching we detele e
// i-1,j
//2. insert character: horse ros, insert s at the end of horse ->horses
//i,j-1  i remains at same position as we added in the back 
//3. replace character: horse ros, replace e with s
//find which one gives minimum count among the 3 operations

//base case
//word1 becomes empty
//return the length of remaining charcters in word2 -> i+1

//word2 becomes empty
//return the length of remaining charcters in word1 -> j+1;

//RECURSIVE
//TC 3^n+3^m
    // int f(int i, int j, string word1, string word2){
    //     //base case
    //     if(i<0)
    //         return j+1;
    //     if(j<0)
    //         return i+1;

    //     //recurrence relation
    //     if(word1[i] == word2[j])
    //         return 0+f(i-1,j-1,word1,word2);
    //     else{
    //         int del = 1 + f(i-1,j,word1,word2);
    //         int ins = 1 + f(i,j-1,word1,word2);
    //         int rep = 1 + f(i-1,j-1,word1,word2);
    //         return min(del,min(ins,rep));
    //     }
    // }
    // int minDistance(string word1, string word2) {
    //     int n1 = word1.size();
    //     int n2 = word2.size();
    //     return f(n1-1, n2-1, word1,word2);
    // }
class Solution {
public:
    int f(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        //base case
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;

        if(dp[i][j] != -1)
            return dp[i][j];
        //recurrence relation
        if(word1[i] == word2[j])
            return dp[i][j] = 0+f(i-1, j-1, word1, word2, dp);
        else{
            int del = 1 + f(i-1, j, word1, word2, dp);
            int ins = 1 + f(i, j-1, word1, word2, dp);
            int rep = 1 + f(i-1, j-1, word1, word2, dp);
            return dp[i][j] = min(del,min(ins,rep));
        }
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1,vector<int> (n2,-1));
        return f(n1-1, n2-1, word1, word2, dp);
    }
};