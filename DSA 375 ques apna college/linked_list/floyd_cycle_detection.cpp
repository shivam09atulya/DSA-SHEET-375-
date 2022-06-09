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

int remove_loop(node *head, node *pos)
{
    node *prev = pos;

    if (!head || !head->next)
        return 0;

    while (true)
    {
        if (pos == head)
        {
            prev->next = NULL;
            return 1;
        }
        prev = pos;
        pos = pos->next;
        head = head->next;
    }
    return 0;
}

int find_loop(node *head)
{
    if (!head || !head->next)
        return 0;

    node *slow = head->next, *fast = head->next->next;

    while (slow && fast->next)
    {
        if (slow == fast)
        {
            remove_loop(head, slow);
            return 1;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return 0;
}

int main()
{
    linkedlist *ll = new linkedlist();
    ll->insert(1);
    ll->insert(3);
    ll->insert(4);
    // ll->insert(4);
    ll->head->next->next->next = ll->head->next;
    cout << find_loop(ll->head) << endl;
    ll->display();
    return 0;
}