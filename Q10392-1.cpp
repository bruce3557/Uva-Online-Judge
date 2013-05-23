#include<stdio.h>
char notp[1000001];
int prime[100001];
main(){
   int i,j,len;
   long long n;
   for(i=1;i<=1000001;i+=2)
       notp[i]=1;
   for(i=3;i<=1000001/i;i+=2)
       if(notp[i])
           for(j=i*i;j<=1000001;j+=2*i)
               notp[j]=0;
   len=0,prime[len++]=2;
   for(i=3;i<=1000001;i+=2)
       if(notp[i])
           prime[len++]=i;
   while(scanf("%lld",&n) && n>0){
       for(i=0;prime[i]*prime[i]<=n && i<len;i++)
           for(;n%prime[i]==0;n/=prime[i])
               printf("    %d\n",prime[i]);
       if(n>1) printf("    %lld\n",n);
       puts("");
   }
}
