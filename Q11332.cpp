#include <stdio.h>
#include <string.h>

void go(char *s, int len) {
	
	if(len == 1) {
		printf("%d\n",s[0]);
		return;
	}
	
	int i,sum = 0,n = 0;
	static char tmp[15];
	
	for(i=0;i<len;i++)
		sum += s[i];
	
	while(sum > 0) {
		tmp[n] = sum%10;
		sum /= 10;
		n++;
	}
	
	go(tmp, n);
	
}

int main() {

	int i,j,n;
	char s[15];
	
	while(gets(s) != NULL && s[0] != '0') {
		
		n = strlen(s);
		
		for(i=0;i<n;i++)
			s[i] -= '0';
		
		if(n == 1) {
			printf("%d\n",s[0]);
		} else {
			go(s,n);
		}
		
	}

	return 0;
}
