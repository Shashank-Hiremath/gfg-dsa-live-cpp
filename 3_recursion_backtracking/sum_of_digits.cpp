//https://practice.geeksforgeeks.org/problems/sum-of-digits1742/1

class Solution{
public:
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
};