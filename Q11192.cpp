#include <stdio.h>
#include <string.h>

char s[110];

int main() {

	int n,i,len,unit,pre,j;

	while(scanf("%d",&n) && n) {
	
		scanf("%s",s);
		len = strlen(s);
		unit = len / n;
		
		pre = 0;
		for(i=unit;i<=len;i+=unit) {
			for(j=i-1;j>=pre;j--)
				printf("%c",s[j]);
			pre = i;
		}
		puts("");
		
	}
	
	return 0;
}
