#include <bits/stdc++.h>

using namespace std;

class node
{

public:
    int data;
    node *next;

    node()
    {
        next = NULL;
        data = 0;
    }

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

void deleteit(node *head)
{
    if (!head || !head->next)
        return;
    head->data = head->next->data;
    node *temp = head->next;
    head->next = head->next->next;
    free(temp);
}

node *removeDuplicates(node *head)
{
    if (!head)
        return NULL;

    if (!head->next)
        return head;

    node *temp = removeDuplicates(head->next);
    if (temp->data == head->data)
    {
        head->next = temp->next;
        free(temp);
        return head;
    }
    while (temp)
    {
        if (head->data == temp->data)
        {
            deleteit(temp);
        }
        temp = temp->next;
    }

    return head;
}

void insert(node *last, node *head, node *temp)
{
    if (!head)
    {
    }
}

node *removeHasing(node *head)
{
    if (!head)
        return NULL;

    if (!head->next)
        return head;

    map<node *, int> m;

    while (head)
    {
        m[head]++;
    }

    for (auto it : m)
    {
        cout << " " << it.first;
    }
}

int main()
{
    linkedlist *ll = new linkedlist();
    // ll->insert(1);
    // ll->insert(1);
    // ll->insert(2);
    // // ll->insert(2);
    // // ll->insert(2);

    int arr[] = {21, 12, 17, 14, 30, 2, 14, 7, 12, 13, 13, 3, 8, 25, 13, 20, 14, 10, 2, 12, 27, 1, 18, 22, 23, 14, 29, 8, 11, 1, 29, 23, 12, 8, 28, 3, 9, 11, 1, 12, 15, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        ll->insert(arr[i]);
    }
    // ll->display();
    // removeDuplicates(ll->head);
    ll->head = removeHasing(ll->head);
    cout << endl;
    // ll->display();
    return 0;
}