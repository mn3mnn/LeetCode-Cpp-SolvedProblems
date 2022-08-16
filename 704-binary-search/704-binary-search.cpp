class Solution {
public:
    int search(vector<int>& nums, int target) {
        int16_t left = 0;
        int16_t right = nums.size() - 1;
        
       while(left <= right){
            
            int16_t m = left + (right - left) / 2;
            int tmp = nums[m];
            if(tmp == target){
                return m;
            }
            else if(tmp > target){
                right = m - 1;
            }
            else{
                left = m + 1;
            }
        }
        return -1;
        
        
        
    }
};