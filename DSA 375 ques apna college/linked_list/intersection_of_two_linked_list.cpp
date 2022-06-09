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

int actual_intersect(node *slow, node *head)
{
    while (true)
    {
        if (head == slow)
        {
            return head->data;
        }
        head = head->next;
        slow = slow->next;
    }
    return -1;
}

int find_intersect(node *head)
{
    node *slow = head->next, *fast = head->next->next;
    while (slow && fast->next)
    {
        if (slow == fast)
        {
            return actual_intersect(slow, head);
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return -1;
}

int intersect(node *head1, node *head2)
{
    if (!head1 && !head2)
        return -1;

    if (!head1 || !head2)
        return -1;

    node *temp = head1;
    while (head1->next)
    {
        head1 = head1->next;
    }
    node *diff = head1;
    head1->next = temp;

    int inn = find_intersect(head2);
    diff->next = NULL;
    return inn;
}

int main()
{
    linkedlist *ll1 = new linkedlist();
    ll1->insert(1);
    ll1->insert(2);
    ll1->insert(3);
    ll1->insert(4);
    ll1->display();
    linkedlist *ll2 = new linkedlist();
    ll2->insert(1);
    ll2->insert(2);
    ll2->insert(3);
    ll2->insert(4);
    ll2->display();
    ll1->head->next->next = ll2->head->next;
    cout << intersect(ll1->head, ll2->head) << endl;
    ll1->display();
    return 0;
}