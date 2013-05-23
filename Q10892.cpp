#include<stdio.h>
#include<algorithm>

int n,prime[150000],len,num[150000];
bool notp[2000001];

main(){
    int i,j,k,tmp,ans;
    
	notp[0] = notp[1] = 1;
    for(i=4;i<2000001;i+=2)
        notp[i] = 1;
    for(i=6;i<2000001;i+=3)
        notp[i] = 1;
    for(i=5,k=2;i<1501;i+=k,k=6-k)
        if(notp[i] == 0){
            for(j=i*i;j<2000001;j+=i)
                notp[j]=1;
        }
    len = 2;
    prime[0] = 2, prime[1] = 3;
    for(i=5,k=2;i<2000001;i+=k,k=6-k)
        if(notp[i]==0)
            prime[len++]=i;
    
	while(scanf("%d",&n) && n){
        memset(num,0,sizeof(num));
        
		tmp = n;
        while(tmp > 1){
            for(i=0;i<len && prime[i]<=tmp && tmp%prime[i];i++);
            tmp /= prime[i];
            num[i]++;
        }
		
        for(i=0,ans=1;i<len && prime[i]<=n;i++)
            if(num[i])
                ans = ans*(2*num[i]+1);
				
        printf("%d %d\n",n,(ans+1)/2);
    }
}
