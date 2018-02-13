#include <iostream>
#include <stdlib.h>
using namespace std;

struct ListNode
{
    int value;
    ListNode *next;
};

#define LEN sizeof(struct ListNode)

ListNode *mergeSortedLinkedList(ListNode *head1, ListNode *head2)
{
    if (!head1)
    {
        return head2;
    }
    if (!head2)
    {
        return head1;
    }

    ListNode *mergedHead = NULL;

    if (head1->value < head2->value)
    {
        mergedHead = head1;
        mergedHead->next = mergeSortedLinkedList(head1->next, head2);
    }
    else
    {
        mergedHead = head2;
        mergedHead->next = mergeSortedLinkedList(head1, head2->next);
    }

    return mergedHead;
}

ListNode *getLinkedList()
{
    int total, value;
    cin >> total;

    ListNode *head = NULL;
    ListNode *p1 = NULL;
    ListNode *p2 = NULL;

    p1 = (struct ListNode *)malloc(LEN);
    p2 = p1;

    cin >> value;
    p1->value = value;

    while (total--)
    {
        if (!head)
        {
            head = p1;
            p2->next = NULL;
        }
        else
        {
            p2->next = p1;
        }

        p2 = p1;

        p1 = (struct ListNode *)malloc(LEN);
        if (total == 0)
        {
            p1->value = -1;
        }
        else
        {
            cin >> p1->value;
        }
    }

    p2->next = NULL;

    free(p1);
    p1 = NULL;
    return head;
}

void printLinkedList(ListNode *pHead)
{
    while (pHead)
    {
        cout << pHead->value << " ";
        pHead = pHead->next;
    }
}

int main()
{

    ListNode *list1 = getLinkedList();
    cout << "first sorted list:" << endl;
    printLinkedList(list1);
    cout << endl;

    ListNode *list2 = getLinkedList();
    cout << "second sorted list:" << endl;
    printLinkedList(list2);
    cout << endl;

    ListNode *mergedList = mergeSortedLinkedList(list1, list2);
    cout << "merged sorted list:" << endl;
    printLinkedList(mergedList);
    cout << endl;

    return 0;
}