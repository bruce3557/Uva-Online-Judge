#include <stdio.h>
#include <algorithm>

int s[2000010];

int main() {
	int n;
	while(scanf("%d",&n) && n) {
		
		for(int i=0;i<n;i++)
			scanf("%d",s+i);
		
		std::sort(s,s+n);
		
		for(int i=0;i<n-1;i++)
			printf("%d ",*(s+i));
		
		printf("%d\n",s[n-1]);
		
	}
	return 0;
}
