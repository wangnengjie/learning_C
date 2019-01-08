void sort(List *plist)
{
    Node *point = *plist;
    Node *nPoint;
    Item temp;
    if (point == NULL)
        return;
    for (; point != NULL; point = point->next)
        for (nPoint = point->next; nPoint != NULL; nPoint = nPoint->next)
        {
            if (point->stuMsg.average > nPoint->stuMsg.average)
            {
                temp = point->stuMsg;
                point->stuMsg = nPoint->stuMsg;
                nPoint->stuMsg = temp;
            }
        }
}