#include <stdio.h>
#include <string.h>

int p[50],k[50],n,m,ans[50];
char s[1010],t[1010];

int main() {
	int i,j;
	
	while(gets(s) != NULL) {
		memset(p,0,sizeof(p));
		memset(k,0,sizeof(k));
		gets(t);
		n = strlen(s);
		m = strlen(t);
		for(i=0;i<n;i++)
			if(s[i] >= 'a' && s[i] <= 'z')
				p[s[i]-'a']++;
		for(i=0;i<m;i++)
			if(t[i] >= 'a' && t[i] <= 'z')
				k[t[i]-'a']++;
		for(i=0;i<26;i++)
			ans[i] = p[i] < k[i] ? p[i] : k[i];
		for(i=0;i<26;i++)
			for(j=0;j<ans[i];j++)
				printf("%c",i+'a');
		puts("");
	}
	
	return 0;
}
