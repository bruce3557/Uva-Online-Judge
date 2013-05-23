#include <stdio.h>
#include <string.h>

int len;
char ter[100];

int main() {
	int n;
	
	while(scanf("%d",&n) && n >= 0) {
		if(n == 0) {
			puts("0");
			continue;
		}
		//printf("%d\n",n);
		len = 0;
		while(n > 0) {
			ter[len] = n%3;
			n /= 3;
			len++;
		}
		for(int i=len-1;i>=0;i--)
			printf("%d",ter[i]);
		puts("");
	}
	
	return 0;
}
