#include <stdio.h>
#include <string.h>

const int MAX = 1000010;

int np;
int prime[MAX/2];
bool notp[MAX+10];
int dp[MAX+10];

int from, end;

inline bool test(int p) {
	int num[15];
	int cnt = 0;
	int tmp = p;
	while(p > 0) {
		num[cnt++] = p%10;
		p/=10;
	}
	for(int i=0;i<cnt;++i)
		num[cnt+i] = num[cnt-1-i];
	for(int i=0;i<cnt;++i)
		num[i] = num[cnt+i];
	for(int i=0;i<cnt;++i) {
		int psum = 0;
		for(int j=0;j<cnt;++j)
			psum = psum*10+num[i+j];
		if( notp[psum] )	return false;
	}
	dp[tmp] = 1;
	return true;
}

inline void Build() {
	for(int i=4;i<=MAX;i+=2)
		notp[i] = true;
	for(int i=9;i<=MAX;i+=3)
		notp[i] = true;
	for(int i=5,k=2;i*i<=MAX;i+=k,k=6-k)
		if( !notp[i] )
			for(int j=i*i;j<=MAX;j+=i)
				notp[j] = 1;
	np = 2;
	prime[0] = 2;	prime[1] = 3;
	for(int i=5;i<=MAX;i+=2)
		if(!notp[i])
			prime[np++] = i;
	for(int i=0;i<np;++i)
		if( test(prime[i]) ) {
			dp[prime[i]] = 1;
			//if(prime[i] == 19937)	puts("VV");
		}
	for(int i=1;i<=MAX;++i)
		dp[i] += dp[i-1];
}

inline bool read() {
	scanf("%d",&from);
	if(from == -1)	return false;
	scanf("%d",&end);
	return true;
}

inline void Solve() {
	int answer = dp[end]-dp[from-1];
	if(answer == 0)	puts("No Circular Primes.");
	else if(answer == 1) puts("1 Circular Prime.");
	else	printf("%d Circular Primes.\n",answer);
}

int main() {
	Build();
	while(read())	Solve();
	return 0;
}
