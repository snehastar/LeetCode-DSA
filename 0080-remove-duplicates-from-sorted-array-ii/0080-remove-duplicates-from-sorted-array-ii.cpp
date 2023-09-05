class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //two pointer approach
        int i=2;
        int n = nums.size();
        if(n<3) return n;
        // the intution behind this ->  go through all the
        //  elements, along with that check if the 
		// current element has been included previously or not
		// if included skip it, else add it
        //It's like nums[i ] saying do i belong to nums[indx] position or not by checking with nums[indx-2], if nums[i] == nums[indx-2] means we will have three duplicates in a row so move ahead
        for(int j=2; j<n; j++){
            if(nums[j] != nums[i-2]){
                nums[i] = nums[j];  
                i++;
            }             
        }    
        return i;
    }
};