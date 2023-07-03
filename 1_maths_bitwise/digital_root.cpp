//https://leetcode.com/problems/add-digits/description/


class Solution {
public:


    //Optimal O(1)
    //https://leetcode.com/problems/add-digits/solutions/3455419/detailed-explanation-repeated-digit-sum-congruence-formula/
    // int addDigits(int num) {
    //     return 1 + (num - 1) % 9;
    // }


    //O(log*n)
    //https://www.geeksforgeeks.org/iterated-logarithm-logn/
    int sumOfDigits(int n){
        if(n < 0){
            return sumOfDigits(-n);
        }
        // int sum = 0;
        // while(n > 0){
        //     sum += n%10;
        //     n /= 10;
        // }
        // return sum;
        if(n == 0){
            return 0;
        }
        return n%10 + sumOfDigits(n/10);
    }
    int addDigits(int n) {
        if(n < 0){
            return addDigits(-n);
        }
        int ans = sumOfDigits(n);
        if(ans/10 == 0){
            return ans;
        }
        return addDigits(ans);
    }
};