#include <iostream>
using namespace std;

/* 输入一个数组，将数组中所有奇数位于数组前半部分，所有偶数位于后半部分 */
void reorderOddAndEven(int *numbers,unsigned int length,bool (*func)(int));

/* 判断一个整数是否为偶数 */
bool isEven(int n);

int main(){

    int *pInput = new int[10];
    int i=0;
    while(i < 10){
        cin>>pInput[i++];
    }
    reorderOddAndEven(pInput,10,isEven);
    
    for(i=0;i<10;i++){
        cout<<pInput[i]<<" ";
    }
    cout<<endl;

    return 0;
}

/*
 * @desc   输入一个数组，将数组中所有奇数位于数组前半部分，所有偶数位于后半部分
 * @param  int * numbers 输入的数组（指向第一个元素的指针）
 * @param  int length 输入数组的长度
 * @param  bool (*func) 函数指针 返回值为bool型，参数为int
 * @return void
 */
void reorderOddAndEven(int *numbers,unsigned int length,bool (*func)(int)){
    if(numbers == NULL || length == 0){
        return;
    }
    
    int *begin = numbers,*end = numbers + length - 1;
    while(begin < end){
        
        /* 移动头指针直到遇到一个偶数 */
        while(begin < end && !func(*begin)){
            begin++;
        }

        /* 移动尾指针直到遇到一个奇数 */
        while(begin < end && func(*end)){
            end--;
        }

        if(begin < end){
            int temp = *begin;
            *begin = *end;
            *end = temp;
        }
    }
}

/*
 * @desc   判断一个整数是否为偶数
 * @param  int n
 * @return bool true/false 
 */
bool isEven(int n){
    return n&0x1 == 0;
}