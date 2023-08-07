//https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

int countOfNodes(struct Node* root){
    if(!root)
        return 0;
    return 1 + countOfNodes(root->left) + countOfNodes(root->right);
}
bool isCompleteBinaryTree(struct Node* curr_node, int curr_node_index, int n){
    if(!curr_node)
        return 1;
    if(curr_node_index >= n)
        return 0;
    return isCompleteBinaryTree(curr_node->left, 2*curr_node_index+1, n) && 
            isCompleteBinaryTree(curr_node->right, 2*curr_node_index+2, n);
}
bool isHeap(struct Node* tree) {
    int n = countOfNodes(tree);
    if(!isCompleteBinaryTree(tree, 0, n))
        return 0;
    
    if(tree->left){
        if(tree->data < tree->left->data)
            return 0;
        if(!isHeap(tree->left))
            return 0;
    }
    if(tree->right){
        if(tree->data < tree->right->data)
            return 0;
        if(!isHeap(tree->right))
            return 0;
    }
    // if(tree->left && (tree->data < tree->left->data || !isHeap(tree->left)) ||
    //   tree->right && (tree->data < tree->right->data || !isHeap(tree->right)))
    //     return 0;
    return 1;
}