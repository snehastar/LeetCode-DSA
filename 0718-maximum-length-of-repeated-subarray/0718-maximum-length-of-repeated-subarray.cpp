//TABULATION
//REFER TO LONGEST COMMON SUBSEQUENCE
//convert the problem to substring by removing the else case as it was calculating for the break points too
// we want continuation in a substring
//ans will be stored as the maximum value here instead of at the last index 
//dry run through table to get to ans
//num1 = [4,5,6,7] num2 = [4,5,7,7]
//ans = 2 => [4,5] length = 2
//it is stored at index (2,2) and is the maximum value
//       4 5 7 7
//     0 1 2 3 4
//   0 0 0 0 0 0
// 4 1 0 1 0 0 0
// 5 2 0 0 2 0 0
// 6 3 0 0 0 0 0
// 7 4 0 0 0 0 1
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1));
        //base case
        for(int i=0; i<=n1; i++)
            dp[i][0] = 0;
        for(int i=0; i<=n2; i++)
            dp[0][i] = 0;    
        int maxi = 0;
        //iteration in opposite direction: bottom up
        for(int i1=1; i1<=n1; i1++){
            for(int i2=1; i2<=n2; i2++){
                //copy the recurrence relation
                if(nums1[i1-1] == nums2[i2-1])
                    dp[i1][i2] = 1 + dp[i1-1][i2-1];
                else
                    dp[i1][i2] = 0;
                maxi = max(maxi,dp[i1][i2]);
            }
        }
        return maxi;
    }
};