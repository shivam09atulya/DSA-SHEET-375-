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

node *merge(vector<linkedlist *> v)
{
    if (v.empty())
        return NULL;

    for (auto it : v)
    {
    }
}

int main()
{
    linkedlist *ll1 = new linkedlist();
    ll1->insert(1);
    ll1->insert(4);
    ll1->insert(5);
    ll1->display();
    linkedlist *ll2 = new linkedlist();
    ll2->insert(1);
    ll2->insert(3);
    ll2->insert(4);
    ll2->display();
    linkedlist *ll3 = new linkedlist();
    ll3->insert(2);
    ll3->insert(6);
    ll3->display();
    vector<linkedlist *> ll;
    ll.push_back(ll1);
    ll.push_back(ll2);
    ll.push_back(ll3);
    for (auto it : ll)
    {
        cout << " " << it;
    }
    return 0;
}