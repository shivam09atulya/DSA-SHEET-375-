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

node *rev_in_pairs(node *head)
{
    if (!head)
        return NULL;

    if (!head->next)
        return head;

    node *prev = NULL;
    node *temp = head->next;
    node *rheal = head->next;

    while (head && head->next)
    {
        head->next = temp->next;
        temp->next = head;
        if (prev)
            prev->next = temp;

        prev = head;
        head = head->next;
        if (head)
            temp = head->next;
    }
    return rheal;
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
    ll->insert(5);
    ll->insert(7);
    ll->insert(4);
    ll->insert(8);
    ll->insert(9);
    ll->insert(0);
    ll->display();
    ll->head = rev_in_pairs(ll->head);
    ll->display();
    return 0;
}