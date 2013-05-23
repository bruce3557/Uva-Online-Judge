#include <stdio.h>

int main() {
	int a,b,t;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&a,&b);
		if(a < b)	puts("<");
		else if(a > b)	puts(">");
		else		puts("=");
	}
	
	return 0;
}
