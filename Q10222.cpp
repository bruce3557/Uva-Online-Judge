#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n,t1,t2;
char QQ[1000010];
char s[] = "34567890-=ertyuiop[]dfghjkl;'cvbnm,./ ",t[] = "1234567890qwertyuiopasdfghjklzxcvbnm, ";

int main() {
	int i,j;
	t1 = strlen(s);
	t2 = strlen(t);
	while(gets(QQ) != NULL) {
		n = strlen(QQ);
		for(j=0;j<n;j++) {
			for(i=0;i<t1 && tolower(QQ[j]) != s[i];i++);
			printf("%c",t[i]);
		}
		puts("");
	}
	
	return 0;
}
