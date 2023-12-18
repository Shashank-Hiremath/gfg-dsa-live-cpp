//https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

int getNthFromLast(Node *head, int n)
{
    Node* curr = head, *prev = head;
    n--;
    while(n-- && curr)
        curr = curr->next;
    if(!curr)
        return -1;
    while(curr->next)
    {
        curr = curr->next;
        prev = prev->next;
    }
    return prev->data;
}