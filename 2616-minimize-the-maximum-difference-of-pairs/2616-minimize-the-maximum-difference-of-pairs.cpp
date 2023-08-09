class Solution {
public:
    int find(vector<int>& nums, int n, int pairs, int p) {
        int cnt = 0;
        for(int i=0; i<n-1 and cnt < p; ) {
            if(nums[i+1] - nums[i] <= pairs) {
                cnt++;
                i += 2;
            }
            else {
                i++;
            }
        }
        return cnt;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n-1] - nums[0];
        while(low <= high) {
            int mid = low + (high-low) / 2;
            int cntPairs = find(nums, n, mid, p);
            if(cntPairs >= p) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};