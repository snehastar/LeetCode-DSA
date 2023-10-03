class Solution {
public:
    string longestPalindrome(string s) {
        string ans ="";
        int count = 0;
        int n = s.size();
        if(n == 0 || n == 1)
            return s;
        pair<int,int> p1;
        int maxi = INT_MIN;
        int left1;
        int right1;
        for(int i=1; i<n-1; i++){
            left1 = i-1;
            right1 = i+1;
            while(left1 >=0 && right1<n && s[left1] == s[right1]){
                left1--;
                right1++;
            } 
            if(right1-left1+1 > maxi){
                p1.first = left1+1;
                p1.second = right1-1;
                maxi = right1-left1+1;
            }   
        }  

        pair<int,int> p2;
        int left2;
        int right2;
        
        
        for(int i=0; i<n-1; i++){
            left2 = i;
            right2 = i+1;
            while(left2 >=0 && right2<n && s[left2] == s[right2]){
                left2--;
                right2++;
            } 
            if(right2-left2+1 > maxi){
                p2.first = left2+1;
                p2.second = right2-1;
                maxi = right2-left2+1;
            }   
        } 

        if(p2.second-p2.first < p1.second-p1.first+1){
           p2.second = p1.second;
           p2.first = p1.first;
        }
        for(int i=p2.first; i<=p2.second; i++)
            ans += s[i];

        return ans;  
    }
};