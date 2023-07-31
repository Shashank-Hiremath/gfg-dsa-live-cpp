//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> um;
        int cnt, ma, n = s.size(), i, left, right;
        if(n==0)
            return 0;
        um[s[0]]++;
        ma = 1;
        left=0;
        right=1;
        while(right<n)
        {
            if(um[s[right]])
            {
                um[s[left]]--;
                left++;
            }
            else
            {
                um[s[right]]++;
                right++;
            }
            cout<<left<<" "<<right<<"\n";
            ma = max(ma, right-left);
        }
        return ma;
    }
};