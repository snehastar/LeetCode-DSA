class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int count = 0;
        string a = "";
        int j = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '(')
                count++;
            if(s[i] == ')')
                count--;
            if(count == 0){
                string ans= s.substr(j+1, i-j-1);
                a += ans;
                j=i+1;
            }
        } 
        return a;     
    }
};