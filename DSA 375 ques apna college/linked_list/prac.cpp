Node *reorder(Node *head)
{
    if (!head)
        return NULL;

    if (!head->next)
        return head;

    Node *counter = head;
    Node *mhead = head->next;

    int size = 0;
    while (counter)
    {
        counter = counter->next;
        size++;
    }

    if (size % 2 == 0)
    {

        Node *temp = head->next;
        Node *other = head->next->next;
        Node *prev = NULL;
        while (true)
        {
            temp->next = head;
            head->next = other;
            if (prev)
            {
                prev->next = temp;
            }
            prev = head;
            head = temp;
            if (!head->next->next)
                break;
            head = head->next->next;
            temp = head->next;
            other = head->next->next;
        }
        return mhead;
    }

    else
    {
        Node *temp = head->next;
        Node *other = head->next->next;
        Node *prev = NULL;
        int times = size / 2;
        while (times--)
        {
            temp->next = head;
            head->next = other;
            if (prev)
            {
                prev->next = temp;
            }
            prev = head;
            head = temp;
            if (!prev->next->next)
                break;
            head = head->next->next;
            temp = head->next;
            other = head->next->next;
        }

        return mhead;
    }
}

Node *thisisit(Node *head)
{
    if (!head)
        return NULL;

    if (!head->next)
        return head;

    Node *temp = thisisit(head->next);
    head->next = temp;

    Node *counter = head;
    int size = 0;
    while (counter)
    {
        size++;
        counter = counter->next;
    }

    Node *arrange = reorder(head->next);
    head->next = arrange;
}
void reorderList(Node *head)
{
    head = thisisit(head);
}