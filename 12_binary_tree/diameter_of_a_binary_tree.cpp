//https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

int f(Node* curr, int &ma)
{
    if(!curr)
        return 0;
    int left = f(curr->left, ma);
    int right = f(curr->right, ma);
    ma = max(ma, left+right+1);
    return 1 + max(left, right);
}

int diameter(Node* node) {
    int ma = 0;
    f(node, ma);
    return ma;
}