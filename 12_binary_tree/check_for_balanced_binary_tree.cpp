//https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

int f(Node* curr, bool &balanced)
{
    if(!curr)
        return 0;
    int left = f(curr->left, balanced);
    int right = f(curr->right, balanced);
    if(abs(left-right)>1)
        balanced = 0;
    return 1+max(left, right);
}
bool isBalanced(Node *root)
{
    bool balanced=1;
    f(root, balanced);
    return balanced;
}