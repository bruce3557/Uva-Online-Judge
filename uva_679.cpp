#include <stdio.h>
#include <string.h>
#include <assert.h>

int n, k;

inline void read() {
	scanf("%d%d",&n,&k);
}

inline void Solve() {
	int start = 1;
	--n;	--k;
	for(int i=0;i<n;++i) {
		if(k) {
			if( k%2 )	start = start*2+1;
			else		start = start*2;
			k /= 2;
		} else
			start *= 2;
	}
	//assert(start < (1<<(n+1)));
	printf("%d\n",start);
}

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		read();
		Solve();
	}
	scanf("%*d");

	return 0;
}
