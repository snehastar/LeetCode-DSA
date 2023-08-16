// RECURSIVE
// TC: O(N^2)
// SC: O(N) STACK SPACE
class Solution {
public:

    int f(int i, vector<int>& nums, int target, int sum){
        if(i<0 && sum == target) 
            return 1;

        if(i < 0)
            return 0;
      
        int pos = f(i-1,nums,target,sum-nums[i]);
        int neg = f(i-1,nums,target,sum+nums[i]);

        return pos+neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return f(n-1,nums,target,0);    
    }
};

