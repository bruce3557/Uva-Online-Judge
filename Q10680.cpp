#include <stdio.h>
#define MAX 1000000

long long s[MAX+10];
bool notp[MAX+10];
int prime[300000],len;

long long GCD(long long a,long long b) {
	if(b == 0)	return a;
	return GCD(b,a%b);
}

bool test(int a) {
	int i;
	for(i=0;i<len && prime[i] <= a;i++) {
	
	}
}

int main() {
	int n,i,j,k;
	long long gcd,a,b;
	
	for(i=4;i<=MAX;i+=2)
		notp[i] = 1;
	for(i=9;i<=MAX;i+=3)
		notp[i] = 1;
	for(i=5,k=2;i<=MAX/i;i+=k,k=6-k)
		if(notp[i] == 0) {
			for(j=i*i;j<=MAX;j+=i)
				notp[j] = 1;
		}
	len = 2;
	prime[0] = 2, prime[1] = 3;
	for(i=5,k=2;i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			prime[len++] = i;
	
	s[1] = 1, s[2] = 2;
	for(i=3;i<=MAX;i++) {
		test(i);
		gcd = GCD(i,s[i-1]);
		a = i/gcd;
		b = s[i-1]/gcd;
		s[i] = gcd*a*b;
		while(s[i]%10 == 0)
			s[i] /= 10;
		s[i] %= 10;
	}
	
	while(scanf("%d",&n) && n)
		printf("%lld\n",s[n]);
	
	return 0;
}
