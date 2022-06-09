#include <bits/stdc++.h>

using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = NULL;
    }
};

class linkedlist
{
public:
    node *head;
    node *last;

    linkedlist()
    {
        head = NULL;
        last = NULL;
    }
    void insert(int data);
    void display();
};

void linkedlist::insert(int data)
{
    if (head == NULL)
    {
        head = new node(data);
        last = head;
    }

    else
    {
        node *temp = new node(data);
        last->next = temp;
        last = temp;
    }
}

void linkedlist::display()
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void display_rec(node *head)
{
    if (head->next == NULL)
    {
        cout << head->data;
        return;
    }

    cout << head->data;
    display_rec(head->next);
}

// node *rearrange(node *head, int size)
// {
//     if (!head)
//         return NULL;

//     if (!head->next)
//         return head;
// }

node *reorder(node *head)
{
    if (!head)
        return NULL;

    if (!head->next)
        return head;

    node *counter = head;
    node *mhead = head->next;

    int size = 0;
    while (counter)
    {
        counter = counter->next;
        size++;
    }

    if (size % 2 == 0)
    {

        node *temp = head->next;
        node *other = head->next->next;
        node *prev = NULL;
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
        node *temp = head->next;
        node *other = head->next->next;
        node *prev = NULL;
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

node *mainorderList(node *head)
{
    if (!head)
        return NULL;

    if (!head->next)
        return head;

    node *temp = mainorderList(head->next);
    head->next = temp;

    node *counter = head;
    int size = 0;
    while (counter)
    {
        size++;
        counter = counter->next;
    }

    node *arrange = reorder(head->next);
    head->next = arrange;

    return head;
}

int main()
{
    linkedlist *ll = new linkedlist();
    ll->insert(1);
    ll->insert(2);
    ll->insert(3);
    ll->insert(4);
    ll->insert(5);
    ll->insert(6);
    ll->insert(7);
    ll->insert(8);
    ll->insert(9);
    ll->insert(10);
    ll->insert(11);
    ll->insert(12);
    ll->insert(13);
    ll->insert(14);
    ll->insert(15);
    ll->insert(16);
    ll->insert(17);
    ll->insert(1);
    ll->insert(2);
    ll->insert(3);
    ll->insert(4);
    ll->insert(5);
    ll->insert(6);
    ll->insert(7);
    ll->insert(8);
    ll->insert(9);
    ll->insert(10);
    ll->insert(11);
    ll->insert(12);
    ll->insert(13);
    ll->insert(14);
    ll->insert(15);
    ll->insert(16);
    ll->insert(17);
    ll->insert(1);
    ll->insert(2);
    ll->insert(3);
    ll->insert(4);
    ll->insert(5);
    ll->insert(6);
    ll->insert(7);
    ll->insert(8);
    ll->insert(9);
    ll->insert(10);
    ll->insert(11);
    ll->insert(12);
    ll->insert(13);
    ll->insert(14);
    ll->insert(15);
    ll->insert(16);
    ll->insert(17);
    ll->insert(1);
    ll->insert(2);
    ll->insert(3);
    ll->insert(4);
    ll->insert(5);
    ll->insert(6);
    ll->insert(7);
    ll->insert(8);
    ll->insert(9);
    ll->insert(10);
    ll->insert(11);
    ll->insert(12);
    ll->insert(13);
    ll->insert(14);
    ll->insert(15);
    ll->insert(16);
    ll->insert(17);
    // ll->display();
    ll->head = mainorderList(ll->head);
    ll->display();
    return 0;
}