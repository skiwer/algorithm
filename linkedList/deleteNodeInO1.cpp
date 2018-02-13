#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int value;
    struct Node* next;  
};

#define LEN sizeof(struct ListNode)
#define N 10

/*
 * @desc   尾插法创建链表
 * @param  ListNode* L(头节点，传的是引用)
 * @return void
 */
void createLinkedList(ListNode** L){
    int i = N;
    int value;
    ListNode *end,*p;
    *L = (ListNode*)malloc(LEN);
    end = *L;
    while(i--){
        p = (ListNode*)malloc(LEN);
        cin>>value;
        p->value = value;
        end->next = p;
        end = p;
    }
    end->next = NULL;
}

/*
 * @desc  根据索引（此处指节点的位置，头结点为1，之后累加）从链表查找节点
 * @param ListNode* head,传入链表的头结点
 * @param int index 索引
 */
ListNode* getNodeByIndex(ListNode** head,int index){
    ListNode *p = NULL;
    ListNode *pHead = *head;
    while(index--){
        p = pHead->next;
        if (!pHead || !p)
        {
            return NULL;
        }
        pHead = pHead->next;
    }
    return p;
}

/*
 * @desc   用平均O(1)的时间复杂度从链表中删除某个节点
 * @param  
 * @param  
 * @return void
 */
void deleteNodeInO1(ListNode** pHead,ListNode* toBeDeleted){
    if(!pHead || !toBeDeleted)
        return;

    if(toBeDeleted->next != NULL){
        ListNode* pNext = toBeDeleted->next;
        toBeDeleted->value = pNext->value;
        toBeDeleted->next = pNext->next;
        delete pNext;
        pNext = NULL;
    }else if(*pHead == toBeDeleted){
        delete toBeDeleted;
        toBeDeleted = NULL;
        pHead = NULL;
    }else{
        ListNode * head = *pHead;

        while(head->next != toBeDeleted){
            head = head->next;
        }

        head->next = NULL;
        delete toBeDeleted;
        toBeDeleted = NULL;
    }
}

/*
 * @desc   从头到尾打印链表
 * @param  ListNode** L 指向头结点的指针
 * @return void 
 */
void printLinkedList(ListNode** L){

    ListNode* pHead = *L;
    while(pHead){
        cout<<pHead->value<<" ";
        pHead = pHead->next;
    }
}

int main(){

    ListNode** L;
    createLinkedList(L);//按用户输入创建链表
    
    int index;
    cin>>index;

    ListNode* nodeToBeDeleted;
    nodeToBeDeleted = getNodeByIndex(L,index);

    deleteNodeInO1(L,nodeToBeDeleted);

    printLinkedList(L);

    return 0;
}
