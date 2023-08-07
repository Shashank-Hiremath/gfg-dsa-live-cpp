//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

vector<int> topView(Node *root)
{
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        if(mp.find(curr.second) == mp.end()) { //Add only if no previous occurrence
            mp[curr.second] = curr.first->data;
        }
        if(curr.first->left)
            q.push({curr.first->left, curr.second-1});
        if(curr.first->right)
            q.push({curr.first->right, curr.second+1});
    }
    vector<int> ans;
    for(auto x: mp)
        ans.push_back(x.second);
    return ans;
}