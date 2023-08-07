//https://practice.geeksforgeeks.org/problems/floor-in-bst/1

bool inorder(Node* curr, int x, int &prev)
{
    if(!curr)
        return 1;
    if(!inorder(curr->left, x, prev))
        return 0;
    if(curr->data > x)
        return 0;
    prev = curr->data;
    return inorder(curr->right, x, prev);
}
int floor(Node* root, int x) {
    if(root && root->data == x)
        return x;
    int prev = -1;
    inorder(root, x, prev);
    return prev;
}