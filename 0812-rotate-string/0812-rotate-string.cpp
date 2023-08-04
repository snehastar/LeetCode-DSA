class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if (n != goal.size())
            return false;
        
        for (int i = 0; i < n; i++) {
            // check if ith character is equal to the first
            // character of goal
            if (s[i] == goal[0]) {
                // chheck prefix of s with suffix of goal
                if (s.substr(i) == goal.substr(0, n - i)) {
                    // check suffix of goal with prefix of s
                    if (s.substr(0, i) == goal.substr(n - i))
                        return true;
                }
            }
        }

        return false;
    }
};