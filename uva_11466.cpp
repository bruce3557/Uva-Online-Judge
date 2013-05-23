#include <stdio.h>
#include <string.h>
#define MAX (10000000)

inline long long Max(long long a, long long b) { return a>b?a:b; }
inline long long abs(long long x) {	return (x>=0?x:(-x)); }

long long n;
long long prime[MAX],pcnt;
bool notp[MAX+10];

inline void Build() {
	for(int i=4;i<=MAX;i+=2)
		notp[i] = true;
	for(int i=9;i<=MAX;i+=3)
		notp[i] = true;
	int i=5,k=2;
	for(;i*i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			for(int j=i*i;j<=MAX;j+=i)
				notp[j] = true;
	pcnt=2;
	prime[0]=2,prime[1]=3;
	i=5,k=2;
	for(;i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			prime[pcnt++] = i;
}

int main() {
	Build();
	while(scanf("%lld",&n) && n) {
		//if(n <= 2) { puts("-1"); continue; }
		long long ans=-1;
		long long temp=abs(n);
		n = abs(n);
		int count=0;
		for(int i=0;i<pcnt && temp > 1 && prime[i]*prime[i] <= n;++i) {
			if(temp%prime[i] == 0) {
				ans = prime[i];
				++count;
				while(temp%prime[i] == 0)	temp/=prime[i];
			}
		}
		if(temp == 1) {
			if(count <= 1)	ans = -1;
		} else {
			if(count >= 1)	ans = temp;
			else			ans = -1;
		}
		printf("%lld\n",ans);
	}

	return 0;
}
