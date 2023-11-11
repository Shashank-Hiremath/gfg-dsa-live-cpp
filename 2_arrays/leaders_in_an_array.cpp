//https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

    

class Solution{
    //Function to find the leaders in the array.
    public:
    
    bool isLeader(int a[], int n, int i){
        for(int j=i+1;j<n;j++)
            if(a[j] > a[i])
                return false;
        return true;
    }
    
    vector<int> leaders(int a[], int n){
        vector<int> ans;
        
        // for(int i=0;i<n;i++)
        //     if(isLeader(a, n, i))
        //         ans.push_back(a[i]);
        
        int maxSoFar = a[n-1];
        vector<int> maxFromRight(n);
        maxFromRight[n-1] = a[n-1];
        
        for(int i=n-2;i>=0;i--){
            maxSoFar = max(maxSoFar, a[i]);
            maxFromRight[i] = maxSoFar;
            
            // maxFromRight[i] = max(maxFromRight[i+1], a[i]);
        }
        
        for(int i=0;i<n;i++)
            if(a[i] == maxFromRight[i])
                ans.push_back(a[i]);
        
        return ans;
    }
};