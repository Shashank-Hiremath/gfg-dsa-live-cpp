//https://practice.geeksforgeeks.org/problems/odd-or-even3618/1

class Solution{   
public:
    string oddEven(int n){
        // if(n&1 == 0)
        //     return "even";
        // else
        //     return "odd";
        vector<string> s{"even", "odd"};
        return s[n&1];
    }
};