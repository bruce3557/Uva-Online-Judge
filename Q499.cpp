#include <stdio.h>
#include <string.h>

int fre[100];
char s[1000010];

int main() {
	int i,j,n,max;
	
	while(gets(s) != NULL) {
		n = strlen(s);
		memset(fre,0,sizeof(fre));
		for(i=0;i<n;i++) {
			if(s[i] >= 'a' && s[i] <= 'z')
				fre[s[i]-'a'+26]++;
			else if(s[i] >= 'A' && s[i] <= 'Z')
				fre[s[i]-'A']++;
		}
		max = 0;
		for(i=0;i<52;i++)
			if(max < fre[i])
				max = fre[i];
		for(i=0;i<26;i++)
			if(max == fre[i])
				printf("%c",i+'A');
		for(i=26;i<52;i++)
			if(max == fre[i])
				printf("%c",i-26+'a');
		printf(" %d\n",max);
	}
	
	return 0;
}
