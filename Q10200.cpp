#include<stdio.h>
#define MAX 10005
bool notp[MAX+1];
int prime[3000],len,sol[10010];

bool check(int n){
    int i;
    for(i=0;i<len && prime[i]*prime[i]<=n;i++)
        if(n%prime[i]==0)
            return 0;
    return 1;
}

main(){
    int i,j,k,n,m;
    double ans;
    notp[0]=notp[1]=1;
    for(i=4;i<MAX+1;i+=2)
        notp[i]=1;
    for(i=9;i<MAX+1;i+=3)
        notp[i]=1;
    for(i=5,k=2;i<=110;i+=k,k=6-k)
        if(notp[i]==0)
            for(j=i*i;j<=MAX;j+=i)
                notp[j]=1;
    prime[len++]=2;
    for(i=3;i<=MAX;i+=2)
        if(notp[i]==0)
            prime[len++]=i;
    for(i=0;i<=10000;i++)
        if(check(i*(i+1)+41))
            sol[i]=1;
    for(i=1;i<=10000;i++)
        sol[i]+=sol[i-1];
    while(scanf("%d %d",&n,&m)!=EOF)
        printf("%.2lf\n",100.00*(double)(sol[m]-sol[n-1])/(double)(m-n+1)+1e-9);
}
