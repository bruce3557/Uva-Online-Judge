#include <stdio.h>

int s[] = { 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012 };

int main() {

	int n,c=0;
	
	while(scanf("%d",&n) != EOF) {
		if(c)	puts("");
		else	c = 1;
		printf("%d\n",s[n-1]);
	}
	
	return 0;
}
