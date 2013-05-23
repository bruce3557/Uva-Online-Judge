#include <stdio.h>
#include <string.h>

char s[1000010],word[1000010];

int main() {
	int i,j,len,n;
	
	while(gets(s) != NULL) {
		len = strlen(s);
		for(i=j=0;i<=len;i++) {
			if(s[i] == '\0') {
				n = j;
				for(j=n-1;j>=0;j--)
					printf("%c",word[j]);
				puts("");
				j = 0;
			} else if(s[i] == ' ') {
				n = j;
				for(j=n-1;j>=0;j--)
					printf("%c",word[j]);
				printf(" ");
				j = 0;
			} else {
				word[j++] = s[i];
			}
		}
	}
	
	return 0;
}
