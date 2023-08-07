//https://practice.geeksforgeeks.org/problems/vertical-sum/1

void f(Node* curr, int vertical_level, map<int, int> &mp)
{
    mp[vertical_level] += curr->data;
    if(curr->left)
        f(curr->left, vertical_level-1, mp);
    if(curr->right)
        f(curr->right, vertical_level+1, mp);
}
void verticalSum(Node *root) {
    map<int, int> mp;
    f(root, 0, mp);
    for(auto x: mp)
        cout<<x.second<<" ";
}