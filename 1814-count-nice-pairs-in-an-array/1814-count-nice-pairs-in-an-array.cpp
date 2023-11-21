class Solution {
public:    
    int countNicePairs(vector<int>& nums) {
	long count = 0, mod = 1e9 + 7;
	unordered_map<int, long> mp;
	for(auto& num : nums) mp[num - rev(num)]++;        
	for(auto& pair : mp)  
		count = (count + (pair.second * (pair.second - 1)) / 2) % mod; 
	
	return count;
}
    
    int rev(int a) {
        int revnum = 0;
        
        while(a) {
            int last = (a % 10);
            revnum = last + (revnum*10);
            a /= 10;
        }
        return revnum;
    }
};