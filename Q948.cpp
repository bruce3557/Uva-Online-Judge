#include<stdio.h>
main(){
    int t,i,j,fib[45],n;
    fib[0]=0,fib[1]=1;
    for(i=2;i<45;i++)   fib[i]=fib[i-1]+fib[i-2];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d = ",n);
        for(i=44;i>0 && fib[i]>n;i--);
        for(;i>=2;i--)
            if(fib[i]<=n)   printf("1"),n-=fib[i];
            else            printf("0");
        puts(" (fib)");
    }
}
