#include <iostream>
using namespace std;

/*
 * 计算某个整数的二进制表示中1的个数
 * （基于分析得到n&n-1可以将整数n的二进制表示中最右边的一个1变成0，于是循环这个操作直到n变成0）
 * 【类似】判断一个数是否为2的整数倍只需判断n&n-1是否为0，因为2的倍数的2进制表示中只有1位为1
 */
int numberOf1(int n){
    int count = 0;
    while(n){
        count++;
        n = n&(n-1);
    }
    return count;
}

int main(){
    
    int n = 35345;

    cout<<numberOf1(n)<<endl;

    return 0;
}