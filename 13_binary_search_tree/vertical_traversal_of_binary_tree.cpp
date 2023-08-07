//https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

//Using map
void verticalOrder(Node *root)
{
    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        mp[curr.second].push_back(curr.first->data);
        if(curr.first->left)
            q.push({curr.first->left, curr.second-1});
        if(curr.first->right)
            q.push({curr.first->right, curr.second+1});
    }
    for(auto x: mp)
        for(auto y: x.second)
            cout<<y<<" ";
}

//Using multimap
void verticalOrder(Node *root)
{
    multimap<int, int> mmp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        mmp.insert({curr.second, curr.first->data});
        if(curr.first->left)
            q.push({curr.first->left, curr.second-1});
        if(curr.first->right)
            q.push({curr.first->right, curr.second+1});
    }
    for(auto x: mmp)
        cout<<x.second<<" ";
}