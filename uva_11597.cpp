#include <stdio.h>
#include <string.h>

int main() {
	int n,c=0;
	
	while(scanf("%d",&n) && n)
		printf("Case %d: %d\n",++c,n/2);
	
	return 0;
}
