//https://leetcode.com/problems/valid-palindrome/description/

class Solution {
public:
    bool isPalindrome(string s) {
        int i, j;
        for(i=0,j=0;s[i];i++)
            if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9')
                s[j++] = s[i]>='a' && s[i]<='z' ? s[i] - 32: s[i];
        string s1 = s.substr(0,j);
        for(i=0;i<j/2;i++)
            if(s1[i] != s1[j-i-1])
                return 0;
        return 1;
    }
};