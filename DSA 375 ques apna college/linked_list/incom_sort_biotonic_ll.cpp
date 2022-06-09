#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;

    node()
    {
        prev = next = NULL;
        data = 0;
    }

    node(int val)
    {
        data = val;
        prev = next = NULL;
    }
};

class bll
{
public:
    node *head, *last;

    void insert(int val);

    bll()
    {
        head = NULL;
        last = NULL;
    }
};
void bll::insert(int val)
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

void display(node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node *sorting(node *head)
{
    if (!head)
        return NULL;

    if (!head->next)
        return head;

    node *temp = sorting(head->next);
    if (temp->data > head->data)
    {
        head->next = temp;
        temp->prev = head;
        head->prev = NULL;
    }

    else
    {
        node *before = NULL;
        node *rhead = temp;
        while (temp)
        {
            if (temp->data > head->data)
            {
                before->next = head;
                head->prev = before;
                head->next = temp;
                temp->prev = head;
                break;
            }
            before = temp;
            temp = temp->next;
        }
        if (before->data < head->data)
        {
            before->next = head;
            head->prev = before;
            head->next = NULL;
        }
        return rhead;
    }
    return NULL;
}
int main()
{
    bll *l = new bll();
    l->insert(2);
    l->insert(5);
    l->insert(7);
    // l->insert(12);
    // l->insert(10);
    // l->insert(6);
    l->insert(4);
    l->insert(1);
    display(l->head);
    l->head = sorting(l->head);
    display(l->head);
    return 0;
}