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

node *remove_it(node *head)
{
    if (!head)
        return NULL;

    if (!head)
    {
        free(head);
        return NULL;
    }

    head->data = head->next->data;
    node *temp = head->next;
    head->next = head->next->next;
    free(temp);
    return head;
}

// node *del_greater(node *head)
// {
//     if (!head)
//         return NULL;

//     if (!head->next)
//         return head;

//     node *mhead = head;
//     while (head->next)
//     {
//         if (head->next->data > head->data)
//         {
//             head = remove_it(head);
//         }

//         else
//             head = head->next;
//     }
//     int t = 10;
//     while (t--)
//     {
//         del_greater(mhead);
//     }
//     return mhead;
// }

node *compute(node *head)
{
    if (!head)
        return NULL;

    if (!head->next)
        return head;

    node *temp = compute(head->next);
    head->next = temp;
    if (head->data < head->next->data)
    {
        head = remove_it(head);
    }
    return head;
}
int main()
{
    linkedlist *ll = new linkedlist();
    ll->insert(32);
    ll->insert(433);
    ll->insert(636);
    ll->insert(121);
    ll->insert(831);
    ll->insert(102);
    ll->insert(695);
    // ll->insert(2);
    // ll->insert(3);
    ll->display();
    ll->head = compute(ll->head);
    ll->display();
    return 0;
}