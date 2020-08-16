void addNode(List *plist, Item t)
{
    Node *point;
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->stuMsg = t;
    temp->next = NULL;
    if (*plist == NULL)
    {
        temp->pre = NULL;
        *plist = temp;
    }
    else
    {
        point = *plist;
        while (point->next != NULL)
            point = point->next;
        temp->pre = point;
        point->next = temp;
    }
}