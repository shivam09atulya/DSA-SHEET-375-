#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node()
    {
        data = 0;
        prev = next = NULL;
    }

    node(int val)
    {
        data = val;
        prev = next = NULL;
    }
};

class double_ll
{
public:
    node *head = NULL, *last = NULL;

    void insert(int val);
    void display();
};

void double_ll::insert(int val)
{
    if (!head)
    {
        head = new node(val);
        last = head;
    }

    else
    {
        node *t = new node(val);
        last->next = t;
        t->prev = last;
        last = t;
    }
}

void double_ll::display()
{
    node *temp = head;
    while (temp)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout << endl;
}
// Recursive solution
// node *rev(node *head)
// {
//     if (!head)
//         return NULL;

//     if (!head->next)
//         return head;

//     node *temp = rev(head->next);
//     node *rhead = temp;
//     while (temp->next)
//     {
//         temp = temp->next;
//     }

//     head->next = temp->next;
//     temp->next = head;
//     head->prev = temp;
//     return rhead;
// }

node *rev(node *head)
{
    if (!head)
        return NULL;

    if (!head->next)
        return head;

    node *b = NULL, *c = head, *a = head->next;

    while (c)
    {
        c->prev = a;
        c->next = b;

        if (!a)
            break;
        b = c;
        c = c->prev;
        a = a->next;
    }
    return c;
}

int main()
{
    double_ll *dll = new double_ll();
    dll->insert(1);
    dll->insert(2);
    dll->insert(3);
    dll->insert(4);
    dll->insert(5);
    dll->display();
    dll->head = rev(dll->head);
    dll->display();
    return 0;
}