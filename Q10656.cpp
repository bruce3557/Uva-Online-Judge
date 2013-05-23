#include <stdio.h>

int n,s[1010];

int main() {
	
	int i,j,len;
	
	while(scanf("%d",&n) && n) {
		for(i=len=0;i<n;i++) {
			scanf("%d",&j);
			if(j)	s[len++] = j;
		}
		
		for(i=0;i<len-1;i++)
			printf("%d ",s[i]);
		printf("%d\n",s[len-1]);
	}

	return 0;
}
