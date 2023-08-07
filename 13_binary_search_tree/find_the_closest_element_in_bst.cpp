//https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1

int maxDiff(Node *root, int k)
{
    Node* curr = root;
    int mi = INT_MAX, ans = -1;
    while(curr)
    {
        if(abs(curr->data - k) < mi)
        {
            mi = abs(curr->data - k);
            ans = curr->data;
        }
        if(k < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return mi;
}
