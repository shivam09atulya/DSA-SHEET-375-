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

void reorder(node *head)
{
    if (!head || !head->next || !head->next->next)
        return;

    node *counter = head;
    int size = 0;
    stack<node *> s;
    while (counter)
    {
        s.push(counter);
        counter = counter->next;
        size++;
    }

    for (int i = 0; i < size / 2; i++)
    {
        node *temp = s.top();
        s.pop();
        temp->next = head->next;
        head->next = temp;
        head = head->next->next;
    }
    head->next = NULL;
}

int main()
{
    linkedlist *ll = new linkedlist();
    ll->insert(1);
    ll->insert(2);
    ll->insert(3);
    ll->insert(4);
    ll->display();
    reorder(ll->head);
    ll->display();
    return 0;
}

// https://leetcode.com/problems/reorder-list/discuss/802119/C%2B%2B-really-simple-solution-using-stack-with-explanations

// In this we used a stack in which we entered the nodes and then insert the top element of stack into two nodes until we run out of
// loop