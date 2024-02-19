class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // if(n == 1) return;
        if(k >= n) k = k % n;
        vector<int> temp;
        
        // storing the last k variable into temp
        for(int i = n-k; i < n; i++) {
            temp.push_back(nums[i]);
        }
        
        // shifting
        for(int i = n-1; i >= k; i--) {
            nums[i] = nums[i-k];            
        }
        
        // put back temp
        int j = 0;
        for(int i = 0; i < k; i++) {
            nums[i] = temp[j];
            j++;
        }
    }
};