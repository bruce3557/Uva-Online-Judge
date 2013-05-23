#include <stdio.h>
#include <string.h>
#include <math.h>
char notp[1005100];
int len,prime[30000];
int ans[1000100],lena;
int main(){
	
	int i,j,k;
	int L,U,min,max,minp,maxp;

	for(i=4;i<46341;i+=2)
		notp[i] = 1;
	for(i=6;i<46341;i+=3)
		notp[i] = 1;
		
	prime[0] = 2, prime[1] = 3;
	len = 2;
	
	for(k=2,i=5;i<46341;i+=k,k=6-k)
		if(notp[i] == 0 && i<46341){
			for(j=i*i;j<46341;j+=i)
				notp[j] = 1;
			prime[len++] = i;
		}
	
	while(scanf("%d%d",&L,&U) != EOF){
		
		memset(notp,0,sizeof(notp));
		
		for(i = 0;prime[i] <= U/prime[i]; i++){
			j = (L/prime[i])*prime[i];
			if(j < L)	j += prime[i];
			for(;j-L <= U-L;j+=prime[i])
				if(j>prime[i] && j-L >= 0)
					notp[j-L] = 1;
		}
		
		lena = 0;
		if(L <= 1) notp[0] = 1;
		for(i = U;i >= L;i--)
			if(i-L >= 0 && notp[i-L] == 0)
				ans[lena++] = i;
		
		if(lena <= 1){
			puts("There are no adjacent primes.");
			continue;
		}
		
		min = ans[lena-2] - ans[lena-1], minp = lena-2;
		max = ans[lena-2] - ans[lena-1], maxp = lena-2;
		for(i=lena-3;i>=0;i--){
			if(min > ans[i]-ans[i+1]){
				min = ans[i]-ans[i+1];
				minp = i;
			}
			if(max < ans[i]-ans[i+1]){
				max = ans[i]-ans[i+1];
				maxp = i;
			}
		}
		
		printf("%d,%d are closest, %d,%d are most distant.\n",ans[minp+1],ans[minp],ans[maxp+1],ans[maxp]);
	}
	
	return 0;
}
