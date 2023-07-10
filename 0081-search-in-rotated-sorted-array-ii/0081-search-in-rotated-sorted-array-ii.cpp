class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        
        if(n == 1 && arr[0] != target) return false;
        else if(n == 1&& arr[0] == target) return true;
        
        int low = 0, high = n-1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(arr[mid] == target) return true;
            
            if(arr[low] == arr[mid] && arr[mid] == arr[high]) {
                low++;
                high--;
                continue;
            }
            
            if(arr[low] <= arr[mid]) {
                if(arr[low] <= target && target <= arr[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            
            if(arr[mid] <= arr[high]) {
                if(arr[mid] <= target && target <= arr[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        
        return false;
    }
};