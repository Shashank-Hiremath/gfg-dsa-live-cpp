//https://leetcode.com/problems/minimum-absolute-difference/description/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size(), i, min_diff;
        if(n <= 1){
            return ans;
        }
        sort(arr.begin(), arr.end());
        
        min_diff = arr[1] - arr[0];
        ans = {{arr[0], arr[1]}};
        for(i=2;i<n;i++){
            int diff = arr[i] - arr[i-1];
            if(diff == min_diff){
                ans.push_back({arr[i-1], arr[i]});
            }
            else if(diff < min_diff){
                min_diff = diff;
                ans = {{arr[i-1], arr[i]}};
            }
        }
        return ans;
    }
};