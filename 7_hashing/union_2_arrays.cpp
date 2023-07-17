class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        if(m > n){
            return intersection(b, a);
        }
        

        unordered_map<int, int> cnta, cntb, cntab;
        int i;
        vector<int> ans;
        for(i=0;i<m;i++){
            cnta[a[i]]++;
            cntab[a[i]]++;
        }
        for(i=0;i<n;i++){
            cntb[b[i]]++;
            cntab[b[i]]++;
        }
        
        for(auto x: cntab){
            int key = x.first;
            // if(cnta[key]>0 && cntb[key]>0){ //Use this for Intersection
            if(cnta[key]>0 || cntb[key]>0){
                ans.push_back(key);
            }
        }
        return ans;
    }
};