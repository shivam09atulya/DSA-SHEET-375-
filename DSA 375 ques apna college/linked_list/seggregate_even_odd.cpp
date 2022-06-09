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

node *divide(node *head)
{
    if (!head)
        return NULL;

    if (!head->next)
        return head;

    node *temp = divide(head->next);

    if (head->data % 2 == 0)
    {
        head->next = temp;
        return head;
    }

    else
    {
        node *prev = NULL;
        node *rhead = temp;

        if (temp->data % 2 != 0)
        {
            head->next = temp;
            return head;
        }

        while (temp)
        {
            if (temp->data % 2 != 0)
            {
                prev->next = head;
                head->next = temp;
                return rhead;
            }
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        head->next = NULL;
        return rhead;
    }
}

int main()
{
    linkedlist *ll = new linkedlist();
    ll->insert(1);
    ll->insert(5);
    ll->insert(3);
    ll->insert(2);
    ll->display();
    ll->head = divide(ll->head);
    ll->display();
    return 0;
}