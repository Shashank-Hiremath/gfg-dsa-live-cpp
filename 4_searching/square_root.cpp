//https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1){
            return x;
        }
        long long int lo = 0, hi = x, mid;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if(mid * mid < x){
                lo = mid + 1;
            }else if(mid * mid > x){
                hi = mid;
            }else{
                return mid;
            }
        }
        return lo-1;
    }
};