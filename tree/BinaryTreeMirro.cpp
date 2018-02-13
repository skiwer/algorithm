#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

struct BinaryTree
{
    int value;
    BinaryTree *left;
    BinaryTree *right;
};

void binaryTreeMirro(BinaryTree* treeNode){

    
    if(!treeNode || (treeNode->left == NULL && treeNode->right == NULL))
        return;

    BinaryTree* tmp = treeNode->left;
    treeNode->left = treeNode->right;
    treeNode->right = tmp;

    if(treeNode->left){
        binaryTreeMirro(treeNode->left);
    }
    
    if(treeNode->right){
        binaryTreeMirro(treeNode->right);
    }

}

BinaryTree *getBinaryTree()
{
    cout << "按层次输入二叉树节点（0表示对应位置为空，-1表示输入结束）：" << endl;

    queue<BinaryTree *> que;

    BinaryTree *head = (BinaryTree *)malloc(sizeof(BinaryTree));
    head->left = NULL;
    head->right = NULL;

    int v;
    cin >> v;

    if (v == 0 || v == -1)
    {
        free(head);
        head = NULL;
        return head;
    }

    head->value = v;
    que.push(head);

    while (!que.empty())
    {
        BinaryTree *parent = que.front();
        que.pop();

        cin >> v;

        if (v == -1)
            break;

        if (v == 0)
        {
            parent->left = NULL;
        }
        else
        {
            BinaryTree *lChild = (BinaryTree *)malloc(sizeof(BinaryTree));
            lChild->left = NULL;
            lChild->right = NULL;

            lChild->value = v;
            parent->left = lChild;
            que.push(lChild);
        }

        cin >> v;

        if (v == -1)
            break;

        if (v == 0)
        {
            parent->right = NULL;
        }
        else
        {
            BinaryTree *rChild = (BinaryTree *)malloc(sizeof(BinaryTree));
            rChild->left = NULL;
            rChild->right = NULL;

            rChild->value = v;
            parent->right = rChild;
            que.push(rChild);
        }
    }

    return head;
}

void printBinaryTreeByLevel(BinaryTree *head)
{
    if (!head)
        return;

    queue<BinaryTree *> que;
    que.push(head);

    while (!que.empty())
    {
        BinaryTree *parent = que.front();
        que.pop();

        cout << parent->value << " ";

        if (parent->left)
            que.push(parent->left);

        if (parent->right)
            que.push(parent->right);
    }
}

int main(){

    BinaryTree *tree = getBinaryTree();

    printBinaryTreeByLevel(tree);
    cout<<endl;

    binaryTreeMirro(tree);

    printBinaryTreeByLevel(tree);
    cout<<endl;

    return 0;

}