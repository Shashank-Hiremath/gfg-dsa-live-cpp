//https://practice.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1

class Solution
{
public:
    int findMax(Node *root)
    {
        if(root == NULL)
            return INT_MIN;
        int left = findMax(root->left);
        int right = findMax(root->right);
        return max({root->data, left, right});
    }
    int findMin(Node *root)
    {
        if(root == NULL)
            return INT_MAX;
        int left = findMin(root->left);
        int right = findMin(root->right);
        return min({root->data, left, right});
    }
};