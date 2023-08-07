//https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1

class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int i=0;
        vector<int> ans(n);
        for(i=0;i<k;i++){
            pq.push(arr[i]);
        }
        for(i=0;i<k-1;i++){
            ans[i] = -1;
        }
        ans[k-1] = pq.top();
        for(i=k;i<n;i++)
            {
                if(arr[i]>pq.top()){
                    pq.pop();
                    pq.push(arr[i]);
                }
                
                ans[i] = pq.top();
            }
        return ans;
    }
};