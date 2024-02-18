class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0;
        vector<int> temp;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                zero++;
            }
            else if(nums[i] != 0) {
                temp.push_back(nums[i]);
            }
        }
        
        if(zero == 0) return;
        
        int j = 0;        
        for(int i = 0; i < temp.size(); i++) {
            nums[j] = temp[i];
            j++;
        }
        
        for(int i = 0; i < zero; i++) {
            nums[j] = 0;
            j++;
        }
    }
};