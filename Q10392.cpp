#include<stdio.h>
#define MAX 1000000

char notp[MAX+10];
int prime[100000];

main(){

	int c=0,len;
	long long n,i,j,k;
   
	for(i=4;i <= MAX;i+=2)
		notp[i] = 1;
	for(i=9;i <= MAX;i+=3)
		notp[i] = 1;
	 
	for(i=5,k=2;i<=MAX/i;i+=k,k=6-k)
		if(notp[i] == 0)
			for(j=i*i;j<=MAX;j+=i)
				notp[j]=1;
			   
	prime[0] = 2;
	prime[1] = 3;
	len = 2;
	for(i=5,k=2;i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			prime[len++] = i;
			
	while(scanf("%lld",&n) && n > 0){
			   
		for(i=0;prime[i]*prime[i]<=n && i<len;i++)
			for(;n%prime[i]==0;n/=prime[i])
				printf("    %d\n",prime[i]);
			   
		if(n>1) printf("    %lld\n",n);
		puts("");
	}
}
