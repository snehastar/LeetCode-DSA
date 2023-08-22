class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        //initially making an ans string of size num, to store the LCS
        int count = dp[n1][n2];
        string ans = "";
        for(int i=0; i<count; i++)
            ans += '#';
        int len = count-1;//to get the last index as len
        cout<<ans<<endl;

        //traversing through dp array to find lcs
        //if indices value match then store the element in ans and move diaginally left up, else move to max(left, top) element from there
        //do this till one of the strings becomes empty

        int i = n1;
        int j = n2;
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans[len] = str1[i-1];
                len--;
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }else
                j--;
        }
        cout<<ans<<endl;
        string supSeq = "";
        int l = 0;
        int k = 0; 
        //build up the string where str1,str2 != ans string and later add anser letters
        for(int i=0; i<count; i++){
            while(str1[l] != ans[i] && l<n1){
                supSeq += str1[l];
                l++;
            }
            
            while(str2[k] != ans[i] && k<n2){
                supSeq += str2[k];
                k++;
            }
            
            supSeq += ans[i];
            l++;
            k++;
        }
    //for remaining letters in str1 and str2
        while(l<n1){
            supSeq += str1[l];
            l++;
        }
        while(k<n2){
            supSeq += str2[k];
            k++;
        }
        return supSeq;
    }
};