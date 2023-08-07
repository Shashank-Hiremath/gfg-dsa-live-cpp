//https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1

//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int i;
        for(i=0;i<n;i++)
            {
                pq.push(arr[i]);
                if(pq.size()==k+1)
                    pq.pop();
            }
            
        vector<int> ans(k);
        i=k-1;
        while(!pq.empty()){
            ans[i--] = pq.top();
            pq.pop();
        }
        return ans;
	}

};