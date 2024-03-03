class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       
          priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        
          long long ans = 0;
          while (pq.size() >= 1 && pq.top() < k) {              
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
           
            pq.push(min(a, b) * 2 + max(a,b));
            ans++;
          }

          return ans;
    }
};