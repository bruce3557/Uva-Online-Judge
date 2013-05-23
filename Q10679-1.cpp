#include <stdio.h>
#include <string.h>
int fail[1010],plen,tlen;
char P[100010],T[1010];

void calc() {
	int i,j;
	j = 0;
	for(i=1;i<=tlen;i++) {
		if(T[i] == T[j])
			fail[i] = fail[j];
		else
			fail[i] = j;
		while(j > 0 && T[i] != T[j])
			j = fail[j];
		j++;
	}
}

char fit() {
	int i,j;
	for(i=1,j=1;i<=plen;i++) {
		while(j > 0 && T[j] != P[i])
			j = fail[j];
		if(j == tlen)	return 1;
		j++;
	}
	return 0;
}

int main() {
	int t,m;
	
	scanf("%d%*c",&t);
	while(t--) {
		gets(P+1);
		plen = strlen(P+1);
		scanf("%d%*c",&m);
		while(m--) {
			gets(T+1);
			tlen = strlen(T+1);
			calc();
			if(fit())
				puts("y");
			else
				puts("n");
		}
	}
	
	return 0;
}
