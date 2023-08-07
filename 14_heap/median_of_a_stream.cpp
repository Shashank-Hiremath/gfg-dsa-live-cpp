//https://leetcode.com/problems/find-median-from-data-stream/description/
//https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1


int main()
{

    IOS;
    ll n, x;
    priority_queue<int> ma;
    priority_queue<int, vector<int>, greater<int>> mi;
    cin>>n;
    while(n--)
    {
        cin>>x;
        if(ma.empty() || x<=ma.top())
            ma.push(x);
        else
            mi.push(x);
        while(ma.size() > 1 + mi.size())
        {
            mi.push(ma.top());
            ma.pop();
        }
        while(mi.size() > 1 + ma.size())
        {
            ma.push(mi.top());
            mi.pop();
        }
        if((ma.size() + mi.size()) & 1)
            ma.size() > mi.size() ? cout<<ma.top()<<"\n" : cout<<mi.top()<<"\n";
        else
            cout<<(ma.top() + mi.top()) / 2<<"\n";
    }
    return 0;
}
