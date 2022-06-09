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
        cout << head->data << " ";
        return;
    }

    cout << head->data;
    display_rec(head->next);
}

void swap(node *first, node *second)
{
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
}

bool check_this(int counter, node *first, node *second)
{
    if (counter % 2 != 0)
    {
        if (second->data > first->data)
            return false;

        else
            return true;
    }
    else
    {
        if (first->data > second->data)
            return false;
        else
            return true;
    }
}

node *zigzag(node *head)
{
    if (!head)
        return NULL;

    if (!head->next)
        return NULL;

    int counter = 1;
    node *temp = head;
    while (head && head->next)
    {
        if (check_this(counter, head, head->next))
        {
            swap(head, head->next);
        }
        counter++;
        head = head->next;
    }
    return temp;
}

int main()
{
    linkedlist *ll = new linkedlist();
    ll->insert(4);
    // ll->insert(4);
    // ll->insert(20);
    // ll->insert(5);
    // ll->insert(10);
    ll->display();
    zigzag(ll->head);
    ll->display();
    return 0;
}