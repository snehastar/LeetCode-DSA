class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // if(s==t)
        //     return true;
        // return false;  

        // using hashmap
        //if the count doesn't become 0 at the end means it's not an anagram
    
        int n = s.size();
        if(n != t.size())
            return false;
        int arr[26] = {0};
        for(int i=0; i<n; i++){
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        for(int i=0; i<26; i++){
            if(arr[i] != 0)
                return false;
        }
        return true;
    }
};