#include <stdio.h>

int main() {

	long long n,ans;
	long long i,j;

	while(scanf("%lld",&n) != EOF) {
		if(n == 1) {
			puts("1");
			continue;
		}
		i = n/2+1;
		ans = i*i*6-9;
		printf("%lld\n",ans);
	}
	
	return 0;
}
