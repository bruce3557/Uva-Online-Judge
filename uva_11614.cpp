#include <stdio.h>

int main() {
	int t;
	long long st,ed,mid,n,tmp;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%lld",&n);
		
		st = 1, ed = (long long)(1000000000LL);		//binary search
		while(st < ed) {
			mid = (st+ed)/2;
			if(mid % 2)	tmp = (mid+1)/2*mid;
			else		tmp = mid/2*(mid+1);
			if(tmp >= n)
				ed = mid;
			else if(tmp < n)
				st = mid+1;
		}
		
		if(ed%2) {
			if((ed+1)/2*ed > n)	ed--;
		} else {
			if(ed/2*(ed+1) > n) ed--;
		}
		
		printf("%lld\n",ed);
	}

	return 0;
}
