class Solution {
public:
//SPACE OPTIMIZED SOLUTION BOTTOM UP
// we try to break the problems into 2 parts, 0th to last-1 index because last index is adjacent to the 0th index
//1st index to last index
//we use dp for both these arrays and find the maximum values
    int f(int lo, int hi, vector<int>& nums){
        int prev = 0;
        int prev2 = 0;
        for(int i=lo; i<hi; i++){
            int pick = nums[i]+prev2;
            int notpick = 0 + prev;
            int cur = max(pick, notpick);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1) 
            return nums[0];
        return max(f(0,n-1,nums),f(1,n,nums));    
    }
};