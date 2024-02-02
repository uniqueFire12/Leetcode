class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";
        vector<int> ans;
        int nlow = to_string(low).size();
        int nhigh = to_string(high).size();       
        for(int i = nlow; i <= nhigh; i++) {
            for(int j = 0; j < 10-i; j++) {
                int num = stoi(str.substr(j, i));
                if(num >= low && num <= high) ans.push_back(num);
            }
        }
        return ans;
    }
};