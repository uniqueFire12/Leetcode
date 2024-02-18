class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        vector<int> temp;
        for(int i=0; i<nums.size(); i++) {
           if(nums[i] != 0) {
                temp.push_back(nums[i]);
            }
        }
        
        int j = 0;        
        for(int i = 0; i < temp.size(); i++) {
            nums[j] = temp[i];
            j++;
        }
        
        for(int i = temp.size(); i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};