class Solution {
public:
    int lb(vector<int>& nums, int n, int target) {
        int low = 0, high = n - 1;
        int ans = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int ub(vector<int>& nums, int n, int target) {
        int low = 0, high = n - 1;
        int ans = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] > target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lbound = lb(nums, n, target);
        if(lbound == n || nums[lbound] != target) return {-1,-1};
        return {lbound, ub(nums, n, target) - 1};
    }
};