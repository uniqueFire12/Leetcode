class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        int left = low, right = mid + 1, k = 0;
        vector<int> temp;
        
        while(left <= mid and right <= high) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        
        while(left <= mid) {
           temp.push_back(nums[left]);
            left++;
        }
        
        while(right <= high) {
           temp.push_back(nums[right]);
           right++;
        }
        
        for(int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
    void mergeSort(vector<int>& nums, int low, int high) {
        if(low >= high) return;
        
        int mid = low + (high - low) / 2;
        
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
        
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};