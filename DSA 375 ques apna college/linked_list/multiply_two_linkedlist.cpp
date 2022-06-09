#include <bits/stdc++.h>

using namespace std;

class node
{

public:
    long long data;
    node *next;

    node(long long value)
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
    void insert(long long data);
    void display();
};

void linkedlist::insert(long long data)
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

// long long multiplyTwoLists(node *l1, node *l2)
// {
//     if (!l1 && !l2)
//         return 0;

//     if (!l1 || !l2)
//         return 0;

//     long long sum1 = multiplyTwoLists(l1, l2->next);
//     long long sum = 0;
//     long long size = 0;
//     long long size_l1 = 0;
//     node *temp = l1;
//     while (l1)
//     {
//         size_l1++;
//         l1 = l1->next;
//     }

//     size_l1--;
//     while (temp)
//     {
//         sum += temp->data * pow(10, size_l1--);
//         temp = temp->next;
//     }
//     sum = sum * l2->data;
//     while (l2)
//     {
//         l2 = l2->next;
//         size++;
//     }

//     sum *= pow(10, size - 1);
//     return sum + sum1;
// }

long long multiplyTwoLists(node *l1, node *l2)
{

    if (!l1 && !l2)
        return 0;

    if (!l1 && l2)
        return 0;

    if (l1 && !l2)
        return 0;

    long long suml1 = 0, suml2 = 0;
    long long size1 = 0, size2 = 0;
    node *temp1 = l1;
    node *temp2 = l2;
    while (l1)
    {
        size1++;
        l1 = l1->next;
    }
    while (l2)
    {
        size2++;
        l2 = l2->next;
    }
    size1--;
    size2--;
    while (temp1)
    {
        suml1 += temp1->data * pow(10, size1--);
        temp1 = temp1->next;
    }

    while (temp2)
    {
        suml2 += temp2->data * pow(10, size2--);
        temp2 = temp2->next;
    }

    return suml1 * suml2;
}
int main()
{
    linkedlist *ll1 = new linkedlist();
    ll1->insert(8);
    ll1->insert(6);
    ll1->insert(3);
    ll1->insert(1);
    ll1->insert(7);
    // ll1->insert(5);
    // ll1->insert(9);
    // ll1->insert(6);
    // ll1->insert(2);
    // ll1->insert(1);
    // ll1->insert(7);
    // ll1->insert(8);
    // ll1->insert(5);
    // ll1->insert(7);
    // ll1->insert(4);
    ll1->display();

    linkedlist *ll2 = new linkedlist();
    ll2->insert(8);
    ll2->insert(6);
    ll2->insert(3);
    ll2->insert(1);
    ll2->insert(7);
    // ll2->insert(5);
    // ll2->insert(9);
    // ll2->insert(6);
    // ll2->insert(2);
    // ll2->insert(1);
    // ll2->insert(7);
    // ll2->insert(8);
    // ll2->insert(5);
    // ll2->insert(7);
    // ll2->insert(4);

    ll2->display();
    cout << multiplyTwoLists(ll1->head, ll2->head);
    return 0;
}

// 2894627653665581568