//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

//Using BFS
int height(Node* node)
{
    queue<Node*> q;
    q.push(node);
    Node* curr;
    int height=0, size;
    while(node && !q.empty())
    {
        for(size=q.size();size;size--)
        {
            curr = q.front();
            q.pop();
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        height++;
    }
    return height;
}

//Using DFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int f(TreeNode* node)
    {
        if(!node)
            return 0;
        return max(f(node->left), f(node->right)) + 1;
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return f(root);
        // return max(f(root->left), f(root->right));
    }
};