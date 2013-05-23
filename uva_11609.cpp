#include <stdio.h>
#define MAX 1000000007

long long pow(long long b,long long p) {
	if(p == 0)	return 1;
	if(p == 1)	return b;
	long long t = pow(b,p/2);
	if(p & 1)
		return (((t*t)%MAX)*b)%MAX;
	else
		return (t*t)%MAX;
}

long long calc(long long n) {
	int i,j,t=n;
	long long tmp;
	tmp = pow(2,n-1);
	n %= MAX;
	return (tmp*n)%MAX;
}

int main() {
	int t,c=0;
	long long n;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%lld",&n);
		printf("Case #%d: %lld\n",++c,calc(n));
	}
	
	return 0;
}
