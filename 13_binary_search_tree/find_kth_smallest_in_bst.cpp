//https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

int KthSmallestElement(Node *root, int k) //O(n), O(log n). Iterative inorder dfs
{
    Node* curr = root;
    stack<Node*> s;
    while(curr || !s.empty())
    {
        while(curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        if(--k == 0)
            return curr->data;
        curr = curr->right;
    }
    return -1;
}

int KthSmallestElement(Node *root,int k)//O(log n +k),O(1). Morris inorder traversal
{
    Node* curr = root, *pre;
    while(curr)
        if(!curr->left)
        {
            if(--k == 0)
                return curr->data;
            curr = curr->right;
        }
        else
        {
            pre = curr->left;
            while(pre->right && pre->right != curr)
                pre = pre->right;
            if(!pre->right)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                if(--k == 0)
                    return curr->data;
                curr = curr->right;
            }
        }
    return -1;
}