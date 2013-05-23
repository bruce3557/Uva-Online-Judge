#include <stdio.h>
#include <string.h>
#include <math.h>

int base,len;
char s[20];

bool Input() {
	gets(s);
	len = strlen(s);
	base = 0;
	if(len == 1 && s[0] == '0')	return false;
	for(int i=0;i<len;i++) {
		s[i] -= '0';
		if(base < s[i])	base = s[i];
	}
	++base;
	return true;
}

int main() {

	while( Input() ) {
		for(;base < 100;base++) {
			int i,num=0;
			for(i=0;i<len;i++)
				num = num*base+s[i];
			int tmp = (int)sqrt(num);
			if(tmp*tmp == num)	break;
		}
		printf("%d\n",base);
	}

	return 0;
}
