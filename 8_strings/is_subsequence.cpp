//https://leetcode.com/problems/is-subsequence/description/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0, i;
        for(i=0;t[i];i++)
            if(t[i] == s[j])
                j++;
        return !s[j];
    }
};