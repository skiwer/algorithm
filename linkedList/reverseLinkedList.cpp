#include <iostream>
#include <stdlib.h>
using namespace std;

struct ListNode{
    int value;
    ListNode* next;
};

#define LEN sizeof(struct ListNode)

ListNode * reverse(ListNode* pHead){

    ListNode* pNode = pHead;//当前节点
    ListNode* pNext = NULL;//下一节点
    ListNode* pPrev = NULL;//上一个节点
    ListNode* pReversedHead = NULL;//反转后链表的头结点

    while(pNode){
        pNext = pNode->next;

        if(pNext == NULL){
            pReversedHead = pNode;
        }

        pNode->next = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }

    return pReversedHead;

}

ListNode * getLinkedList(){
    int total,value;
    cin>>total;

    ListNode* head = NULL;
    ListNode* p1 = NULL;
    ListNode* p2 = NULL;

    p1 = (struct ListNode*)malloc(LEN);
    p2 = p1;

    cin>>value;
    p1->value = value;
    
    while(total--){
        if(!head){
            head = p1;
            p2->next = NULL;
        }else{
            p2->next = p1;
        }

        p2 = p1;

        p1 = (struct ListNode*)malloc(LEN);
        if(total == 0){
            p1->value = -1;
        }else{
            cin >> p1->value;
        }
        
    }

    p2->next = NULL;

    free(p1);
    p1 = NULL;
    return head;
}

void printLinkedList(ListNode* pHead){
    while(pHead){
        cout<<pHead->value<<" ";
        pHead = pHead->next;
    }
}
int main(){
    ListNode* list = getLinkedList();
    //原始链表
    printLinkedList(list);

    ListNode* reversedList = reverse(list);
    cout<<endl;
    
    //反转后的链表
    printLinkedList(reversedList);

    return 0;
}