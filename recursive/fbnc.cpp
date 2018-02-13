#include <iostream>
using namespace std;
/*
 * 斐波那契数列第n（n=0,1,2,3...）项的值
 * 类似跳台阶与铺瓷砖问题都可以转化为斐波那契数列问题
 */
int fbnc(int n){
    if(n < 2){
        return n;
    }
    int a = 0,b = 1,c;
    while(n-- > 1){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n = 10;//n过大时将会超出int范围
    cout<<fbnc(n)<<endl;
    return 0;
}