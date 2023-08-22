//https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1

// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        long long int fib[n+1], i, m = 1e9+7;//1000000007
        fib[0] = 0;
        fib[1] = 1;
        fib[2] = 2;
        for(i=2;i<=n;i++){
            // fib[i] = fib[i-1] + fib[i-2];
            fib[i] = (fib[i-1]%m + fib[i-2]%m) % m;
        }
        return fib[n];
    }
};