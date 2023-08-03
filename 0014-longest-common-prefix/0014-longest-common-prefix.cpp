class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {        
        sort(strs.begin(), strs.end());
        int n = strs.size();
        int no = min(strs[0].size(),strs[n-1].size()); 
        string ans = "";  
        for(int i=0; i<no; i++){
            if(strs[0][i] == strs[n-1][i] && i<no){
                ans += strs[0][i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};