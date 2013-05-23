#include<stdio.h>
main(){
    int fib[45],i,n,t;
    fib[0]=fib[1]=1;
    for(i=2;i<45;i++)  fib[i]=fib[i-1]+fib[i-2];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=44;fib[i]>n && i>0;i--);
        for(;i>=1;i--)
            if(fib[i]<=n)   printf("1"),n-=fib[i];
            else            printf("0");
        puts("");
    }
}
