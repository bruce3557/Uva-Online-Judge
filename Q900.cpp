#include<stdio.h>
main(){
    long long fib[51];
    int i;
    fib[1]=1,fib[2]=2;
    for(i=3;i<51;i++)   fib[i]=fib[i-1]+fib[i-2];
    while(scanf("%d",&i) && i)  printf("%lld\n",fib[i]);
}
