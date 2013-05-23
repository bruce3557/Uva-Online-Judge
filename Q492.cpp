#include <stdio.h>
#include <string.h>

int len,n;
char s[1000010],word[1000010];

int main() {
	int i,j;
	
	while(gets(s) != NULL) {
		len = strlen(s);
		j = 0;
		for(i=0;i<=len;i++) {
			if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
				word[j++] = s[i];
			} else {
				n = j;
				if(n > 0) {
					if(word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u' || word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U') {
						for(j=0;j<n;j++)
							printf("%c",word[j]);
						printf("ay");
					} else {
						for(j=1;j<n;j++)
							printf("%c",word[j]);
						printf("%cay",word[0]);
					}
				}
				if(s[i] != '\0')
					printf("%c",s[i]);
				else
					puts("");
				j = 0;
			}
		}
	}
	
	return 0;
}
