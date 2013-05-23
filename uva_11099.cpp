#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>

using std::vector;

const int MAXN = 1000000;

int np;
bool notp[MAXN+10];
int prime[MAXN/10*3];
long long ans[MAXN+10];

inline void Build_Prime() {
	notp[0] = notp[1] = true;
	for(int i=4;i<=MAXN;i+=2)
		notp[i] = true;
	for(int i=9;i<=MAXN;i+=3)
		notp[i] = true;
	for(int i=5,k=2;i*i<=MAXN;i+=k,k=6-k) {
		if(notp[i])	continue;
		for(int j=i*i;j<=MAXN;j+=i)
			notp[j] = true;
	}
	np = 2;
	prime[0] = 2, prime[1] = 3;
	for(int i=5,k=2;i<=MAXN;i+=k,k=6-k)
		if(notp[i] == false)
			prime[np++] = i;
}

inline long long Solve(int now) {
	long long x = now;
	if(notp[now] == false)	return x*x;
	long long v = 1;
	vector<int> fac;
	vector<long long> sum;
	
	for(int i=0;i<np && prime[i] <= now;++i) {
		if(now%prime[i])	continue;
		fac.push_back(prime[i]);
		v *= prime[i];
		while( (now%prime[i]) == 0 ) now /= prime[i];
	}
	if( notp[now] == false ) {
		fac.push_back(now);
		v *= now;
	}
	
	int size = fac.size();
	sum.push_back(v);
	
	while(1) {
		int mp = -1;
		int ss = sum.size();
		long long minimum = 100000000000000LL;
		
		for(int i=0;i<ss;++i)
			for(int j=0;j<size;++j) {
				long long next = fac[j]*sum[i];
				if(minimum > next && next > sum[ss-1])	minimum = next;
			}
		
		if(minimum > x)	return minimum;
		sum.push_back(minimum);
	}
}

int main() {
	Build_Prime();
	for(int i=2;i<=MAXN;++i)
		ans[i] = -1;
	ans[1] = 20000000;
	
	int n;
	while( scanf("%d",&n) != EOF ) {
		if(ans[n] != -1) {
			if(ans[n] >= 2000000)	puts("Not Exist!");
			else	printf("%lld\n",ans[n]);
			continue;
		}
		ans[n] = Solve(n);
		if(ans[n] >= 2000000)	puts("Not Exist!");
		else	printf("%lld\n", ans[n]);
	}
	
	return 0;
}
