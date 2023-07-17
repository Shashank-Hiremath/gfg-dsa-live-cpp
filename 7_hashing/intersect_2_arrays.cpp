//https://leetcode.com/problems/intersection-of-two-arrays/description/

class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        if(m > n){
            return intersection(b, a);
        }
        unordered_map<int, int> cntb;
        int i;
        vector<int> ans;
        for(i=0;i<n;i++){
            cntb[b[i]]++;
        }
        for(i=0;i<m;i++)
            if(cntb[a[i]]>0){
                ans.push_back(a[i]);
                cntb[a[i]] = 0;
            }
        return ans;
    }
};