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

BinaryTree* getBinaryTree(){
    cout<<"按层次输入二叉树节点（0表示对应位置为空，-1表示输入结束）："<<endl;
    
    queue<BinaryTree*> que;

    BinaryTree *head = (BinaryTree*)malloc(sizeof(BinaryTree));
    head->left = NULL;
    head->right = NULL;

    int v;
    cin>>v;

    if(v == 0 || v == -1){
        free(head);
        head = NULL;
        return head;
    }

    head->value = v;
    que.push(head);

    while(!que.empty()){
        BinaryTree *parent = que.front();
        que.pop();

        cin>>v;

        if(v == -1)
            break;
        
        if(v == 0){
            parent->left = NULL;
        }else{
            BinaryTree *lChild = (BinaryTree*)malloc(sizeof(BinaryTree));
            lChild->left = NULL;
            lChild->right = NULL;

            lChild->value = v;
            parent->left = lChild;
            que.push(lChild);
        }

        cin>>v;

        if(v == -1)
            break;
        
        if(v == 0){
            parent->right = NULL;
        }else{
            BinaryTree *rChild = (BinaryTree*)malloc(sizeof(BinaryTree));
            rChild->left = NULL;
            rChild->right = NULL;

            rChild->value = v;
            parent->right = rChild;
            que.push(rChild);
        }
    }

    return head;
}

void printBinaryTreeByLevel(BinaryTree *head){
    if(!head)
        return;
    
    queue<BinaryTree*> que;
    que.push(head);

    while(!que.empty()){
        BinaryTree *parent = que.front();
        que.pop();

        cout<<parent->value<<" ";

        if(parent->left)
            que.push(parent->left);
        
        if(parent->right)
            que.push(parent->right);
    }
}

bool tree2HasTree1(BinaryTree* a,BinaryTree* b){
    if(a == NULL)
        return true;
    if(b == NULL)
        return false;
    if(a->value != b->value){
        return false;
    }
    return tree2HasTree1(a->left,b->left) && tree2HasTree1(a->right,b->right);
}

/* a树是否为ｂ树的子树 */
bool isSubTree(BinaryTree* a,BinaryTree* b){
    bool result = false;
    if(a != NULL && b != NULL){
        if(a->value == b->value){
            result = tree2HasTree1(a,b);
        }
        if(!result)
            result = isSubTree(a,b->left);
        if(!result)
            result = isSubTree(a,b->right);
    }
    return result;
}

void testUninitedPointer(){
    BinaryTree* a = (BinaryTree*)malloc(sizeof(BinaryTree));
    if(a->left)
        cout<<"has left node"<<endl;
    else
        cout<<"no left node"<<endl;
}

int main(){

    BinaryTree *A = getBinaryTree();

    printBinaryTreeByLevel(A);
    cout<<endl;

    BinaryTree *B = getBinaryTree();

    printBinaryTreeByLevel(B);
    cout<<endl;

    bool result = isSubTree(A,B);

    if(result)
        cout<<"A is the sub tree of B"<<endl;
    else
        cout<<"A is not the sub tree of B"<<endl;

    return 0;

}