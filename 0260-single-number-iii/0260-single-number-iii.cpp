class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0;
        //find xor of all elements
        //we will we left with a ^ b where a ,b are unique
        for(int i=0; i<nums.size(); i++){
            temp = temp ^ nums[i];
        }
        //cout<<temp<<endl;
        //after getting a^b we search for 1 i.e the index where they are different
        //eg: 5^7 => 101^111 => 010 =>here 1st bit is 1 because 1st index is different in both the numbers

        //find right most set bit in a^b
        int idx = 0;
        while(temp != 0){
            if((temp & 1) == 1){
                break;
            }    
            idx++;
            temp = temp>>1;
        }   
        //cout<<idx<<endl;
        //check for all elements if their idx bit is set then put in one set and if not set put in another set
        //this way a and b will be in different sets because we are comparing that differentiating bit
        //so all the nos having this bit set or not set will be in different groups
        //since they will be repeating twice, performing xor on them will cancel those elements
        int set1 = 0;
        int set2 = 0;
        int mask = 1<<idx; //creating mask 
     
        //cout<<mask;
        for(int i=0; i<nums.size(); i++){
            //to check idx bit is set or not
            if((nums[i] & mask) == 0){
                set1 = set1 ^ nums[i];
            }else{
                set2 = set2 ^ nums[i];
            }
        } 

        return {set1,set2};
    }
};