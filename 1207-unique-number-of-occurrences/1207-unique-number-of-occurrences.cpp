class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      unordered_map<int,int> u;
      unordered_set<int> st;;      
      for(auto i : arr) {
        u[i]++;
      } 
      for(auto &i : u) {
        st.insert(i.second);
      }
      return u.size() == st.size();      
    }
};