#include<stdio.h>
char notp[20000002];
int prime[1270610],twin[100000];
main(){
    int len,i,n,lent,j,k;
    for(i=len=0,prime[len++]=2;i<10000000;i++)
        if(notp[i]==0){
            for(j=k=i*2+3,j+=i;j<10000000;j+=k)
                notp[j]=1;
            prime[len++]=i+i+3;
        }
    for(i=lent=0;i<len && lent<=100000;i++)
        if(prime[i+1]-prime[i]==2)
            twin[lent++]=i;
    while(scanf("%d",&n)!=EOF)
        printf("(%d, %d)\n",prime[twin[n-1]],prime[twin[n-1]+1]);
}
