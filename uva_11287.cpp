#include <stdio.h>
#include <string.h>
#define MAX (100000)

int pcnt,prime[80010];
bool notp[100010];

inline void Build() {
	notp[0]= notp[1] = 1;
	for(int i=4;i<=MAX;i+=2)
		notp[i] = 1;
	for(int i=9;i<=MAX;i+=3)
		notp[i] = 1;
	int i=5,k=2;
	for(;i*i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			for(int j=i*i;j<=MAX;j+=i)
				notp[j] = 1;
	
	pcnt=0;
	for(int i=2;i<=MAX;++i)
		if(notp[i] == 0)
			prime[pcnt++] = i;
}

inline bool isDiv(int num) {
	for(int i=0;i<pcnt && prime[i]*prime[i]<=num;++i)
		if(num%prime[i] == 0)
			return true;
	return false;
}

long long go(long long a,long long b,long long c) {
	if(b == 0)	return 1;
	long long temp = go(a,b/2,c)%c;
	temp = (temp*temp)%c;
	if(b&1)	return (temp*a)%c;
	return temp;
}

int main() {
	Build();
	long long p,a;
	while(scanf("%lld%lld",&p,&a) && p+a) {
		//printf("%d %d\n",n,m);
		bool div=isDiv(p);
		if(!div) { puts("no"); continue; }
		long long ans=go(a,p,p)%p;
		if(ans == a)	puts("yes");
		else			puts("no");
	}
	
	return 0;
}
