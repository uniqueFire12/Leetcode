class Solution {
public:
    int find(vector<int> &a, int n, int sum) {
        int noOfSubarr = 1, perArrSum = 0;
        for(int i=0; i<n; i++) {
            if(perArrSum + a[i] <= sum) {
                perArrSum += a[i];
            } else {
                noOfSubarr++;
                perArrSum = a[i];
            }
        }
        return noOfSubarr;
    }
    int splitArray(vector<int>& a, int k) {
        int n = a.size();
        int low = *max_element(a.begin(), a.end());
        int high = accumulate(a.begin(), a.end(), 0);

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int noOfSubarray = find(a, n, mid);
            if(noOfSubarray <= k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};