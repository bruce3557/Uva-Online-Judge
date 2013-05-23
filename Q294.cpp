#include<stdio.h>
#include<string.h>

int n,m,prime[10001],len,cnt[10001];
bool notp[40000];

main(){
    int t,i,j,max,ans,k;
	
    for(i=4;i<=40000;i+=2)
        notp[i] = 1;
    for(i=9;i<=40000;i+=3)
        notp[i] = 1;
    for(i=5,k=2;i<=40000;i+=k,k=6-k)
        if(notp[i] == 0)
            for(j=i*i;j<=40000;j+=i)
                notp[j]=1;
	
    prime[len++] = 2;
    for(i=3;i<40000;i+=2)
        if(notp[i] == 0)
            prime[len++]=i;
	
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(i=n,max=0;i<=m;i++){
            for(j=0;j<len;j++)
                cnt[j] = 1;
            int tmp = i;
            for(j=0;prime[j]*prime[j]<=i && tmp>1;j++)
                while(tmp%prime[j] == 0){
                    cnt[j]++;
                    tmp /= prime[j];
                }
            if(tmp>1)   tmp = 2;
            for(j=0;prime[j]*prime[j]<=i;j++)
                tmp *= cnt[j];
            if(tmp > max){
                max = tmp;
                ans = i;
            }
        }
		
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",n,m,ans,max);
    }
}
