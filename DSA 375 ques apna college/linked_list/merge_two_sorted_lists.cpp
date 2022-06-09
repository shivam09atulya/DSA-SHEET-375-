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

node *mergeTwo(node *head1, node *head2)
{
    if (!head1 && !head2)
        return NULL;
    if (head1 && !head2)
        return head1;

    if (!head1 && head2)
        return head2;

    mergeTwo(head1->next, head2->next);

    if (head1->data >= head2->data)
    {
        head2->next = head1;
        return head2;
    }

    if (head1->data < head2->data)
    {
        head1->next = head2;
        return head1;
    }
}

int main()
{
    linkedlist *ll1 = new linkedlist();
    // ll1->insert(1);
    // ll1->insert(2);
    // ll1->insert(4);
    ll1->display();

    linkedlist *ll2 = new linkedlist();
    ll2->insert(0);
    // ll2->insert(3);
    // ll2->insert(4);
    ll2->display();

    linkedlist *llm = new linkedlist();

    llm->head = mergeTwo(ll1->head, ll2->head);
    llm->display();
    return 0;
}

// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
//     {
//         if (!l1 && !l2)
//             return NULL;

//         if (l1 && !l2)
//             return l1;

//         if (!l1 && l2)
//             return l2;

//         ListNode *temp = mergeTwoLists(l1->next, l2->next);
//         if (l1 && !l2)
//             return l1;

//         if (!l1 && l2)
//             return l2;

//         if (l1->val >= l2->val)
//         {
//             l2->next = l1;
//             l1->next = temp;
//             return l2;
//         }

//         if (l1->val < l2->val)
//         {
//             l1->next = l2;
//             l2->next = temp;
//             return l1;
//         }

//         return NULL;
//     }
// };