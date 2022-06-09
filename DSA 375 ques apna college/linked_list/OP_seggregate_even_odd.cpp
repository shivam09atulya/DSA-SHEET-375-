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

node *divid(node *head)
{
    if (!head)
        return NULL;

    if (!head->next)
        return head;

    node *last = head, *temp = head;

    while (last->next)
    {
        last = last->next;
    }

    node *prev = NULL;
    node *rhead = head;
    node *thisone = head->next;
    while (temp)
    {
        if (temp->data % 2 != 0)
        {
            if (prev)
                prev->next = temp->next;
            last->next = temp;
            temp->next = NULL;
            last = last->next;
        }
        else
        {
            prev = temp;
        }
        temp = thisone;
        thisone = thisone->next;
    }

    return head;
}
int main()
{
    linkedlist *ll = new linkedlist();
    ll->insert(1);
    ll->insert(2);
    ll->insert(3);
    ll->insert(4);
    ll->display();
    ll->head = divid(ll->head);
    ll->display();
    return 0;
}