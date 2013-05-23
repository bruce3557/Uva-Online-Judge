#include <stdio.h>
#include <string.h>

char s[20000];

int main() {

	int t,n,len,tmp;
	int i,j,k,cc = 0;
	char c;
	
	scanf("%d",&t);
	getchar();
	
	while(t--) {
	
		scanf("%s",s);
		n = strlen(s);
		c = s[0], i = 1,len = 0;
		
		printf("Case %d: ",++cc);
		
		while(i < n) {
			
			for(j=i;j<n;j++) {
				if(s[j] >= '0' && s[j] <= '9') {
					len = len*10 + s[j]-'0';
				} else {
					break;
				}
			}
			
			for(k=0;k<len;k++)
				printf("%c",c);
				
			i = j+1, c = s[j], len = 0;
	
		}
		
		puts("");
	}
	
	return 0;
}
