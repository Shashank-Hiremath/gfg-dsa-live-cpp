//https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1


class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        unordered_map<int, int> um;
        vector<int> ans;
        int i, distinctCount=0;
        for(i=0;i<k;i++){
            if(um[A[i]] == 0)
                distinctCount++;
            um[A[i]]++;
        }
        
        ans.push_back(distinctCount);
        for(i=k;i<n;i++){
            um[A[i-k]]--;
            if(um[A[i-k]] == 0)
                distinctCount--;
            
            if(um[A[i]] == 0)
                distinctCount++;
            um[A[i]]++;
            ans.push_back(distinctCount);
        }
        return ans;
    }
};