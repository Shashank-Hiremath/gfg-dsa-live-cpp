//https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

void serialize(Node *root,vector<int> &A)
{
    queue<Node*> q;
    q.push(root);
    Node* curr;
    while(!q.empty())
    {
        curr = q.front();
        q.pop();
        if(curr)
        {
            A.push_back(curr->data);
            q.push(curr->left);
            q.push(curr->right);
        }
        else
            A.push_back(-1);
    }
}

/*this function deserializes
 the serialized vector A*/
Node * deSerialize(vector<int> &A)
{
    Node* root = new Node(A[0]), *curr;
    int i=1, size;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        curr = q.front();
        q.pop();
        if(A[i]!=-1)
        {
            curr->left = new Node(A[i]);
            q.push(curr->left);
        }
        else
            curr->left = NULL;
        i++;
        if(A[i]!=-1)
        {
            curr->right = new Node(A[i]);
            q.push(curr->right);
        }
        else
            curr->right = NULL;
        i++;
    }
    return root;
}