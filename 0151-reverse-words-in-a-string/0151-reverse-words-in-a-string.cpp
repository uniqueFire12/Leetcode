class Solution {
public:
    string reverseWords(string s) {
        string result;
        int i = 0, n = s.size();
        
        while(i < n) {
            while(i < n and s[i] == ' ') i++;
            
            if(i >= n) break;
            
            int j = i;
            
            while(j < n and s[j] != ' ') j++;
            
            string sub_str = s.substr(i, j-i);
            
            if(result.size() == 0) 
                result = sub_str;
            else 
                result = sub_str + " " + result;
            
            
            i = j+1;
        }
        return result;
    }
};