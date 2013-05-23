#include <stdio.h>
#include <string.h>

char s[1010];
int fre[300];

int main() {
	int t,n,i,max;
	
	scanf("%d%*c",&t);
	while(t--) {
		gets(s);
		memset(fre,0,sizeof(fre));
		n = strlen(s);
		max = 0;
		for(i=0;i<n;i++) {
			if(s[i] >= 'a' && s[i] <= 'z')
				fre[s[i]-'a']++;
			else if(s[i] >= 'A' && s[i] <= 'Z')
				fre[s[i]-'A']++;
		}
		for(i=0;i<26;i++)
			if(fre[i] > max)
				max = fre[i];
		for(i=0;i<26;i++)
			if(fre[i] == max)
				printf("%c",i+'a');
		puts("");
	}
	
	return 0;
}
