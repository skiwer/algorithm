#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

//打印1到最大的n位数【解法1】，循环
void print1ToMaxOfNBits(int n);

//打印1到最大的n位数【解法2】，递归，n=4就发生段错误，效率低下，推荐解法一
void print1ToMaxOfNBitsRecursively(int n);

//递归打印
void printRecursive(char * number, int length, int index);

//number字符数组表示的大数加1
bool increment(char * number, int length);

//打印大数的字符数组时去掉所有前缀0
void beautifulPrint(char * number, int length);


int main(){
    
    int n = 4;

    //print1ToMaxOfNBits(n);//解法一
    print1ToMaxOfNBitsRecursively(n);//解法二

    return 0;
}

/*
 * @desc   打印1到最大的n位数，需考虑大数情况，用字符数组存储大数
 *        【解法一，用循环累加】
 * @param  指定的最大位数
 * @return void
 */
void print1ToMaxOfNBits(int n)
{
    if (n < 1)
        return;

    char *number = new char[n + 1];
    memset(number, '0', n);
    number[n + 1] = '\0'; //char数组结束符

    //number表示的大数加1，判断是否加到了n位最大数，若是则跳出while循环
    while (!increment(number, n))
    {                           
        beautifulPrint(number,n); //输出时将每个字符数组表示的大数前缀的所有0都去掉，如00022则输出22
    }

    delete[] number;//记得释放空间，不然可能引起内存泄露
}

/*
 * @desc   打印1到最大的n位数，需考虑大数情况，用字符数组存储大数
 *        【解法二，用递归遍历，n位全排列问题】
 * @param  int n 给定的最大位数
 * @return void 
 */
void print1ToMaxOfNBitsRecursively(int n){

    if(n < 1){
        return;
    }

    char *number = new char[n + 1];
    memset(number, '0', n);
    number[n + 1] = '\0'; //char数组结束符

    for(int i = 0; i < 10; i++){
        number[0] = i + '0';
        printRecursive(number,n,i); 
    }

    delete[] number;
}

/*
 * @desc   递归遍历所有位，每一位上数字从0到9依次循环，直到遍历完所有情况（n位全排列）
 * @param  char * number 大数的字符数组
 * @param  int  n 给定的最大位数
 * @param  int  index 下次要遍历到的位的下标
 * @return void 
 */
void printRecursive(char * number,int length,int index){

    if(index == length - 1){
        beautifulPrint(number, length);
        return;
    }

    for(int i = 0; i < 10; i++){
        number[index+1] = i + '0';
        printRecursive(number, length, index + 1);
    }

}

/*
 * @desc   number字符数组表示的大数加1
 * @param  char* number 累加前的大数的字符数组表示
 * @param  int   length number数组的长度
 * @return bool  是否加到了最高位，即是否到达了要打印的最后一个大数
 */
bool increment(char *number, int length)
{

    bool isOver = false; //是否加到最高位（index=0）的标志，初始为false

    int iTakeOver = 0; //每次循环的进位，初始为0

    for (int i = length - 1; i >= 0; i--)
    {
        int isum = number[i] - '0' + iTakeOver;

        if (i == length - 1)
        {   
            //从最低位加起，第一次循环
            isum++;
        }

        if (isum >= 10)
        {
            if (i == 0)
            {
                isOver = true;
            }
            else
            {
                isum -= 10;
                iTakeOver = 1;
                number[i] = isum + '0';
            }
        }
        else
        {
            number[i] = isum + '0';
            break;
        }
    }

    return isOver;
}

/*
 * @desc   打印大数的字符数组时去掉所有前缀0
 * @param  char* number 要打印的数组,int length 数组的长度
 * @return void
 */
void beautifulPrint(char *number, int length)
{

    bool isPrintBegin = false;

    for (int i = 0; i < length; i++)
    {
        if (number[i] != '0')
        {
            isPrintBegin = true;
        }

        if (isPrintBegin)
        {
            printf("%c", number[i]);
        }
    }

    printf("\t");
}