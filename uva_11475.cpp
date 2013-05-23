#include <stdio.h>
#include <string.h>
int n,fail[100010];
char s[100010],t[100010];

void calc() {
	int i,j;
	j = 0;
	for(i=1;i<=n;i++) {
		if(t[i] == t[j])
			fail[i] = fail[j];
		else
			fail[i] = j;
		while(j > 0 && t[i] != t[j])
			j = fail[j];
		j++;
	}
}

void match() {
	int i,j;
	j = 1;
	for(i=1;i <= n && j <= n;i++,j++)
		while(j > 0 && s[i] != t[j])
			j = fail[j];
	
	for(i=1;i<=n;i++)
		putchar(s[i]);
	for(i=j;i<=n;i++)
		putchar(t[i]);
	puts("");
}

int main() {
	int i;
	while(gets(s+1) != NULL) {
		n = strlen(s+1);
		for(i=1;i<=n;i++)
			t[i] = s[n-i+1];
		t[i] = '\0';
		calc();
		match();
	}
	
	return 0;
}
