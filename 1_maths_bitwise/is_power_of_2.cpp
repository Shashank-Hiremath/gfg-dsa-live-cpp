//https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0){
            return false;
        }
        long long int longn = n;
        return (longn & (longn-1)) == 0;
    }
};