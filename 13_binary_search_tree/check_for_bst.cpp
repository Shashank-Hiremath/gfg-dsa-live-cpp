//https://practice.geeksforgeeks.org/problems/check-for-bst/1

//By validating range approach
bool f(Node* curr, int mi, int ma)
{
    if(!curr)
        return 1;
    if(curr->data < mi || curr->data > ma)
        return 0;
    return f(curr->left, mi, curr->data-1)
        && f(curr->right, curr->data+1, ma);
}

//By checking order is monotonus increasing or not
bool inorder(Node* curr, int &prev)
{
    if(!curr)
        return 1;
    if(!inorder(curr->left, prev))
        return 0;
    if(curr->data <= prev)
        return 0;
    prev = curr->data;
    return inorder(curr->right, prev);
}
bool isBST(Node* root) {
    // return f(root, INT_MIN, INT_MAX);
    int prev = INT_MIN;
    return inorder(root, prev);
}