class Solution {
public:
    int test(vector<int>& nums, int mid, int threshold) {
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            totalSum += ceil((double) nums[i] / (double) mid);
        }
        return totalSum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int low = 1, high = maxi;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int tSum = test(nums, mid, threshold);
            if(tSum <= threshold) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};