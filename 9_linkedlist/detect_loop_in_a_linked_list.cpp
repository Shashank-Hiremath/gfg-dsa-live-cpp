//https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1


#include<bits/stdc++.h>
int detectloop(Node *head) {
    Node *slow = head, *fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return 1;
    }
    return 0;
}

