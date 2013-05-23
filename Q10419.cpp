#include<stdio.h>

bool notp[1010];
int prime[1001],len,n,m,ans[20],used[100],dp[20][1010];

int go(int sum,int now){

    if(dp[now][sum]!=-1)    return sum;
    if(now==0 && sum==0)    return 0;
    if(now==0 && sum)   return -1;
    if(sum<=0 && now)   return -1;

    for(int i=0;prime[i]<=300 && i<len;i++){
        if(prime[i]==2 && used[i]<1){
            used[i]++;
            ans[now]=prime[i];
            dp[now][sum]=go(sum-prime[i],now-1);
            used[i]--;
        }
        else if(prime[i]!=2 && used[i]<2){
            used[i]++;
            ans[now]=prime[i];
            dp[now][sum]=go(sum-prime[i],now-1);
            used[i]--;
        }
    }
    return dp[now][sum];
}

void print(int sum,int now){
    if(dp[now][sum]==0)
        printf("%d",sum);
    else{
        print(dp[now][sum],now-1);
        printf(" %d",sum-dp[now][sum]);
    }
}

main(){
    int i,j,k,c=0;
    for(i=4;i<=400;i+=2)
        notp[i]=1;
    for(i=9;i<=400;i+=3)
        notp[i]=1;
    for(i=5,k=2;i<=400;i+=k,k=6-k)
        if(notp[i]==0)
            for(j=i*2;j<=400;j+=i)
                notp[j]=1;
    len=0;
    prime[len++]=2;
    for(i=3;i<=350;i+=2)
        if(notp[i]==0)
            prime[len++]=i;
    for(i=0;i<1001;i++)
        for(j=0;j<20;j++)
            dp[j][i]=-1;
    while(scanf("%d %d",&n,&m) && n+m){
        for(i=0;i<100;i++)
            used[i]=0;
        printf("CASE %d:\n",++c);
        go(n,m);
        if(dp[m][n]==-1)
            puts("No Solution.");
        else{
            print(n,m);
            puts("");
        }
    }
}
