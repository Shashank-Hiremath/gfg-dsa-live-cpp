//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

//Using BFS
void bottomView(Node *root)
{
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        mp[curr.second] = curr.first->data;
        if(curr.first->left)
            q.push({curr.first->left, curr.second-1});
        if(curr.first->right)
            q.push({curr.first->right, curr.second+1});
    }
    for(auto x: mp)
        cout<<x.second<<" ";
}

//Using DFS

void f(Node* curr, int vertical_level, int horizontal_level, map<int, pair<int, int>> &mp)
{
    if(mp.find(vertical_level) != mp.end())
    {
        if(mp[vertical_level].first <= horizontal_level)
            mp[vertical_level] = {horizontal_level, curr->data};
    }
    else
        mp[vertical_level] = {horizontal_level, curr->data};
    if(curr->left)
        f(curr->left, vertical_level-1, horizontal_level+1,  mp);
    if(curr->right)
        f(curr->right, vertical_level+1, horizontal_level+1,  mp);
}
void bottomView(Node *root)
{
    map<int, pair<int, int>> mp;
    f(root, 0, 0, mp);
    for(auto x: mp)
        cout<<x.second.second<<" ";
}