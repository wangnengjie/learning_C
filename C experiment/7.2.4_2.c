void sort(List *plist)
{
    Node *head = *plist;
    Node *subhead = head->next;
    Node *temp;
    int count = 0;
    int i, j;
    temp = *plist;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    for (i = 0; i < count - 1; i++)
    {
        head = *plist;
        subhead = head->next;
        temp = NULL;
        for (j = 0; j < count - 1 - i && subhead != NULL; j++)
        {
            if (temp == NULL && head->stuMsg.average > subhead->stuMsg.average)
            {
                *plist = subhead;
                head->next = subhead->next;
                subhead->next = head;
                temp = subhead;
                subhead = head->next;
            }
            else if (head->stuMsg.average > subhead->stuMsg.average)
            {
                temp->next = subhead;
                head->next = subhead->next;
                subhead->next = head;
                temp = subhead;
                subhead = head->next;
            }
            else
            {
                temp = head;
                head = head->next;
                subhead = subhead->next;
            }
        }
    }
}