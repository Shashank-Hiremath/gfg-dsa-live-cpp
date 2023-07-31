//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

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
    unordered_map<TreeNode*, TreeNode*> parent;
    
    void dfs(TreeNode* root)
    {
        if(root->left)
        {
            dfs(root->left);
            parent[root->left] = root;
        }
        if(root->right)
        {
            dfs(root->right);
            parent[root->right] = root;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root);
        // for(auto x: parent)
        //     cout<<x.first->val<<" "<<x.second->val<<"\n";
        unordered_map<TreeNode*, bool> visited;
        TreeNode* curr = q;
        while(curr!=root)
        {
            visited[curr] = 1;
            curr = parent[curr];
        }
        visited[curr] = 1;
        curr = p;
        while(1)
        {
            if(visited[curr])
                return curr;
            curr = parent[curr];
        }
        return root;
    }
};

//Without extra memory approach
Node* lca(Node* root ,int n1 ,int n2 )//O(n), O(1)
{//Does not handle case when only one of n1 and n2 is present
    if(!root)
        return NULL;
    if(root->data == n1 || root->data == n2)
        return root;
    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);
    if(left && right)
        return root;
    return left ? left : right;
}