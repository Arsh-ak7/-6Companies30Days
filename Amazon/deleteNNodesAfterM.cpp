void linkdelete(struct Node *head, int M, int N)
{
    // Add code here
    Node *curr = head;
    if (curr == NULL)
        return;
    while (curr)
    {
        int m = M - 1;
        int n = N;
        while (m-- && curr->next)
        {
            curr = curr->next;
        }
        if (curr == NULL)
            return;
        Node *temp = curr;
        while (n-- && temp->next)
            temp = temp->next;
        curr->next = temp->next;
        curr = curr->next;
    }
}