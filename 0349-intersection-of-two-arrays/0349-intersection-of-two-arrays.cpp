class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i = 0, j = 0;
        
        while(i < n1 and j < n2) {
            
            // duplicates
            if(i > 0 and nums1[i] == nums1[i-1]) {
                i++;
                continue;
            }
            
            if(nums1[i] < nums2[j]) {
                i++;
            }
            else if(nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        
        return ans;
    }
};