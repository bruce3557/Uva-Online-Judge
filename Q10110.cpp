#include <stdio.h>
#include <math.h>

int main() {
	long long n,tmp;
	
	while(scanf("%lld",&n) && n) {
		tmp = sqrt(n);
		if(tmp*tmp == n) {
			puts("yes");
		} else {
			puts("no");
		}
	}
	
	return 0;
}
