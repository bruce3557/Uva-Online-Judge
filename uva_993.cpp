#include <stdio.h>
#include <string.h>

int n, ct;
long long ans;
int digit[11];
long long s[11];

long long multi(int x) {
	long long res = 1;
	while( x > 0 ) {
		res *= (x%10);
		x /= 10;
	}
	return res;
}

void go(int now, int sum, long long sr) {
	if(ans != -1 || sr > n || sr*s[ct-now] < n)	return;
	if(now >= ct) {
		if(sr == n)	ans = sum;
		return;
	}
	for(int i=0;i<10;++i)
		go(now+1, sum*10+i, sr*i);
}

int main() {
	int t;
	s[0] = 1;
	for(int i=1;i<11;++i)
		s[i] = s[i-1]*9;
	
	scanf("%d",&t);
	while(t--) { 
		scanf("%d",&n);
		ans = -1;
		ct = 0;
		int tp = n;
		while(tp > 0) {
			++ct;
			tp /= 10;
		}
		go(0, 0, 1);
		printf("%d\n", ans);
	}
	
	return 0;
}
