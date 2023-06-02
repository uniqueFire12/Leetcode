class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=0; i<numbers.size(); i++) {
            if(mpp.find(target - numbers[i]) != mpp.end()) {
                ans.push_back(mpp[target - numbers[i]] + 1);
                ans.push_back(i+1);
                break;
            }
            mpp[numbers[i]] = i;
        }
        
        return ans;
    }
};