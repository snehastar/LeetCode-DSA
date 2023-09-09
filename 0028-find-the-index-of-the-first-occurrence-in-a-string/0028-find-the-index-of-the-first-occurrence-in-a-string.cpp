class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1 = haystack.size();
        int l2 = needle.size();
        if(l2>l1)
            return -1;

        int count=0;
        int ans = -1;
        int j;
        int k = 0;
        for(int i=0; i<l1; i++){
            count=0;
            k = i;
            j=0;
            while(haystack[i] == needle[j] && j<l2 && i<l1){
                ans = k;
                j++;
                i++;
                count++;
                if(count == l2)
                    return ans;    
            }
            i=k;
        }  
        return -1;
    }
};