//https://leetcode.com/problems/valid-anagram/description/
//5 Solutions: https://leetcode.com/problems/rotate-string/solutions/678931/best-solution-for-an-interview-java-thoughts-and-takeaways/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash_s, hash_t;
        for(char c: s){
            hash_s[c]++;
        }
        for(char c: t){
            hash_t[c]++;
        }
        return hash_s == hash_t;
    }
};