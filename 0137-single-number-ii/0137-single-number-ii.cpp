class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //sort the numbers and start from 1 to n-2 crement by 3 
        //check if nums[i-1] == nums[i] == nums[i+1]
        //if not then nums[i-1] is the one occuring once
        //1,1,1,2,2,2,3,4,4,4 =>3
        //1,1,1,2,2,2,3 =>3 for this case check last number as well 
        //if(i+1) != nums.size() - 1 then check for last element
        //1,2,2,2,3,3,3 =>1
        //tc: O(nlog n) +O(n)

        //create a map to count frequencies of each element
        //tc: O(nlogn) + O(n)

        //non intuitive
        //tc: O(n)
        //create a set of ones and twos where ones has the elements appearing once
        //twos containes elements appearing twice
        //if element appears twice it gets deleted from ones
        //if element appears thrice it  gets deleted from twice
        //hence only elements appearing once will remain in ones
        
        int ones = 0;
        int twos = 0;
        for(int i=0; i<nums.size(); i++){
            ones = (nums[i] ^ ones ) & (~twos);
            twos = (nums[i] ^ twos ) & (~ones);

        }

        return ones;       
    }
};