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
        cout << temp->data;
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

node *segregate(node *head)
{

    if (!head)
        return NULL;

    if (!head->next)
        return head;

    node *temp = segregate(head->next);
    head->next = temp;

    if (head->data == 0)
        return head;

    else
    {
        node *nhead = temp;

        while (temp)
        {
            if (temp->data >= head->data)
            {
                node *aux = new node(head->data);
                aux->next = temp->next;
                temp->next = aux;
                free(head);
                return nhead;
            }
            temp = temp->next;
        }
        return head;
    }
}

int main()
{
    linkedlist *ll = new linkedlist();
    ll->insert(0);
    ll->insert(2);
    ll->insert(2);
    ll->insert(1);
    ll->insert(2);
    ll->insert(0);
    ll->insert(2);
    ll->insert(2);
    ll->display();
    ll->head = segregate(ll->head);
    ll->display();
    return 0;
}