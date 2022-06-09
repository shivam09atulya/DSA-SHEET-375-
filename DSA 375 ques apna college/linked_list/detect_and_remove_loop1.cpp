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

int distance(node *head, node *pos)
{
    if (head == pos)
        return 0;

    if (head->next == pos)
        return 1;

    int size = 0;

    while (head)
    {
        if (head == pos)
        {
            return size;
        }
        size++;
        head = head->next;
    }
}

// void loop_remove(node *head)
// {
// }

// int detect(node *head)
// {
//     if (!head)
//         return 0;

//     if (!head->next)
//         return 0;

//     if (head->next == head)
//     {
//         head->next = NULL;
//         return 1;
//     }

//     node *mhead = head;
//     node *slow = head, *fast = head->next;
//     while (slow && fast)
//     {
//         int small = distance(mhead, slow);
//         int large = distance(mhead, fast);
//         if (small >= large)
//         {
//             // loop_remove(fast);
//             slow->next = NULL;
//             return 1;
//         }
//         slow = slow->next;
//         fast = fast->next;
//     }
//     return 0;
// }

int detect(node *head)
{
    if (!head)
        return -1;

    if (!head->next)
        return 0;

    node *slow = head;
    node *prev = NULL;
    map<node *, int> m;

    while (slow)
    {
        m[slow]++;
        if (m[slow] > 1)
        {
            prev->next = NULL;
            return 1;
        }
        prev = slow;
        slow = slow->next;
    }
    return 0;
}

int main()
{
    linkedlist *ll = new linkedlist();
    ll->insert(1);
    ll->insert(2);
    ll->insert(3);
    ll->insert(4);
    ll->head->next->next->next->next = ll->head->next;
    // ll->display();
    cout << detect(ll->head) << endl;
    ll->display();

    return 0;
}