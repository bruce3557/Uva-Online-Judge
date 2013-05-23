#include <stdio.h>
#define MAX 10000000
char notp[MAX+10];
long long n,len,prime[700000];

int main(){
	long long i,j,k,q;
	long long flag,a;
	notp[0] = notp[1] = 1;
	for(i=4;i<=MAX;i+=2)	notp[i] = 1;
	for(i=6;i<=MAX;i+=3)	notp[i] = 1;
	prime[0] = 2, prime[1] = 3;
	len = 2;
	for(i=5,k=2;i*i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			for(j=i*i;j<=MAX;j+=i)
				notp[j] = 1;
	for(i=5,k=2;i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			prime[len++] = i;
	while(scanf("%lld",&n) != EOF){
		if(n <= 7){
			puts("Impossible.");
			continue;
		}
		flag = 0;
		if(n % 2 == 0){
			for(i=0;i<len && prime[i] <= n;i++)
				if(n > 4 && notp[n-4-prime[i]] == 0){
					flag = 1;
					a = prime[i];
					break;
				}
			if(flag)	printf("2 2 %lld %lld\n",a,n-4-a);
			else		puts("Impossible.");
		} else {
			for(i=0;i<len && prime[i] <= n;i++)
				if(n > 5 && notp[n-5-prime[i]] == 0){
					flag = 1;
					a = prime[i];
					break;
				}
			if(flag)	printf("2 3 %lld %lld\n",a,n-5-a);
			else		puts("Impossible.");
		}
	}	
	return 0;
}
