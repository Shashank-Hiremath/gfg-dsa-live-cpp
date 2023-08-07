//https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

void nearlySorted(int arr[], int num, int K){//O(n log k), O(k)
    priority_queue<int, vector<int>, greater<int>> pq;
    int i;
    for(i=0;i<min(num, K+1);i++)
        pq.push(arr[i]);
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
        if(i<num)
            pq.push(arr[i++]);
    }
}
