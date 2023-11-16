class Solution {
public:
    #define mod 1000000007
    
    long long power(long long x, long long n) {
        if(n == 0) return 1;
        
        long long ans = power(x, n/2);
        
        if(n%2 == 0) {
            ans = (ans*ans) % mod;
        }
        else {
            ans = (ans * ans * x) % mod;
        }
        
        return ans;
    }
    
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n/2 + n%2;        
        return (power(5, even) * power(4, odd)) % mod;
    }
};