class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)  {
        vector<int> ans = {-1,-1};
        long long mid;
        long long index = 1e9+1;
        long long left = 0;
        long long right = nums.size()-1;
        while(left <= right){
            mid = (left+right)/2;
            if(nums[mid] == target){
                index = mid;
                break;
            }else if(nums[mid] < target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        if(index == 1e9+1)
            return ans;

        long long test = index;
       
        while(test>=0 && nums[test] == target){
            test--;
        }

        ans[0] = (int)test+1;

        test = index;
        
        while(test <= right && nums[test] == target){
                test++;
        }
        ans[1] = (int)test-1;
        return ans;
    }
};