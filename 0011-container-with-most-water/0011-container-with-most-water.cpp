class Solution {
public:
    int maxArea(vector<int>& height) { 
        //brute force O(n^2)
        //use 2 pointer approach and move that line whichever is smaller 
        //because we can store maximum water the lines are longer
        int n = height.size();
        int ans = 0;
        int maxi = 0;
        int left = 0;
        int right = n-1;
        while(left <= right){
            ans = min(height[left],height[right]) * (abs(right-left));
            maxi = max(maxi,ans);
            if(height[left]<height[right])
                left++;
            else
                right--;
        }
        
        return maxi;
    }
};