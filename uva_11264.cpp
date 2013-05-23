#include <stdio.h>
#include <string.h>

int n;
int A[1010];
int C[1010];

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",C+i);
		
		int ans = 2;
		A[1] = 1;
		for(int i=2;i<=n;++i) {
			A[ans] = A[ans-1]+C[i];
			bool suc = true;
			for(int j=i+1;j<=n;++j)
				if(A[ans] >= C[j]) {
					suc = false;
					break;
				}
			if(suc)	++ans;
		}
		
		printf("%d\n",ans-1);
	}
	
	return 0;
}
