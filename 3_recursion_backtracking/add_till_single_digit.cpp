//https://leetcode.com/problems/add-digits/description/

class Solution {
public:
    int sumOfDigits(int n){ //m digits O(m)
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
    int addDigits(int n) { //O(m * log m)
        if(n < 0){
            return addDigits(-n);
        }
        //999999999 = 90
        //9 * 100 = 900
        //9 * 1000 = 9000
        int ans = sumOfDigits(n);//38, 11
       
        //If single digit
        if(ans/10 == 0){        //11, 2
            return ans;
        }
        return addDigits(ans);
        //f(n) = f(log(n)) 
    }
};