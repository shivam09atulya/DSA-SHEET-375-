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

node *seggregate(node *head)
{
    if (!head)
        return NULL;

    if (!head->next)
        return head;

    node *temp = seggregate(head->next);
    node *real = temp;
    if (head->data % 2 == 0)
    {
        head->next = temp;
        return head;
    }

    else
    {
        node *prev = NULL;

        while (temp)
        {
            if (temp->data % 2 != 0)
            {
                if (!prev)
                {
                    head->next = temp;
                    return head;
                }
                temp->next = prev->next;
                prev->next = temp;
                return real;
            }
            prev = temp;
            temp = temp->next;
        }
        head->next = prev->next;
        prev->next = head;
    }
    return real;
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
    ll->insert(8);
    ll->display();
    ll->head = seggregate(ll->head);
    ll->display();
    return 0;
}