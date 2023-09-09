class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n = a.size();
        vector<int> t;
        for(int i = 0; i < n; i++) {
            if(a[i] != 0) {
                t.push_back(a[i]);
            }
        }

        for(int i = 0; i < t.size(); i++) {
            a[i] = t[i];
        }

        int nzero = t.size();
        for(int i = nzero; i < n; i++) {
            a[i] = 0;
        }
    }
};