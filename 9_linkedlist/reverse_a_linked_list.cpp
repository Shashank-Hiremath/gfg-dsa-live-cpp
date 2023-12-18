//https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1




//function Template for Java

/* linked list node class:

class Node {
    int data;
    Node next;
    Node(int value) {
        this.value = value;
    }
}

*/

//1st Approach
Node* reverseList(Node *head)
{
    if(!head)
        return head;
    Node *curr = head, *prev = NULL, *temp;
    while(curr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return head;
}

//2nd Approach. Using recursion
Node* reverseList(Node *head)
{
    if(!head || !head->next)
        return head;
    Node *rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;//If not done, will cycle when traversing to print
    return rest;
}

//3rd Approach
Node* reverseList(Node *head)   //Using 2 pointers
{
    Node* curr = head, *next;
    while(curr->next)
    {
        next = curr->next;
        curr->next = next->next;
        next->next = head;
        head = next;
    }
    return head;
}


//4th Approach
Node* headGlobal;

Node* reverse(Node* curr)
{
    if(!curr)
        return NULL;
    if(!curr->next)
    {
        headGlobal = curr;
        return curr;
    }
    Node* tail = reverse(curr->next);
    tail->next = curr;
    curr->next = NULL;
    return curr;
}

Node* reverseList(Node *head)   //Using 1 pointers, recursion, global
{
    reverse(head);
    return headGlobal;
}