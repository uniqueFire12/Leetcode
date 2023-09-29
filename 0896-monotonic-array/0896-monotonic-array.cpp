class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int mon_incr = 0, mon_decr = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] > nums[i+1]) {
                mon_incr++;
            }
        }
        
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] < nums[i+1]) {
                mon_decr++;
            }
        }
        
        if(mon_incr > 0 && mon_decr > 0) {
            return false;
        }
        
        return true;
    }
};