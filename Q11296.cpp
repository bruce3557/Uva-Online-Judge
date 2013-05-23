#include <stdio.h>

int main() {
	
	int n;
	int i,j,tmp;
	unsigned long long ans;
	
	while(scanf("%d",&n) != EOF) {
		
		ans = 0;
		if(n & 1) {
			for(i=1;i<=n;i+=2)
				ans += (n-i)/2+1;
		} else {
			for(i=0;i<=n;i+=2)
				ans += (n-i)/2+1;
		}

		printf("%llu\n",ans);
	}
	
	return 0;
}
