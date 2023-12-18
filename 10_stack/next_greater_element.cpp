//https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1


void nextLargerElement(long long arr[], int n){
    stack<int> s;
    int i;
    for(i=0;i<n;i++)
    {
        while(!s.empty() && arr[s.top()] < arr[i])
        {
            arr[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
    {
        arr[s.top()] = -1;
        s.pop();
    }
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
}