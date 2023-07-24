class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> result;
        
        for(int i = 0; i < words.size(); i++) {
            
            string s = words[i];
            cout << s << endl;
            string temp = "";
            
            for(auto it : s) {
                if(it == separator && temp != "") {
                    result.push_back(temp);
                    temp = "";
                }
                if(it != separator) {
                    temp += it;
                }
            }
            
            if(temp != "") {
                result.push_back(temp);
            }
            
        }
        
        return result;
    }
};