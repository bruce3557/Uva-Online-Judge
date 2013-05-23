#include <stdio.h>
#include <string.h>
#include <algorithm>

char s1[20], s2[20];
char d1[20], d2[20];

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%s%s",s1,s2);
		strcpy(d1, s1);
		strcpy(d2, s2);
		std::sort(s1,s1+strlen(s1));
		std::sort(s2,s2+strlen(s2));
		if( strcmp(s1, s2) )	puts("Not Equal");
		else if( check(d1, d2) )	puts("Equal");
		else	puts("Not Equal");
	}
	
	return 0;
}
