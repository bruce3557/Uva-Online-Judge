#include <stdio.h>
#include <string.h>

char s[100];

char trans(char x) {
	if(x >= 'A' && x <= 'C')		return '2';
	else if(x >= 'D' && x <= 'F')	return '3';
	else if(x >= 'G' && x <= 'I')	return '4';
	else if(x >= 'J' && x <= 'L')	return '5';
	else if(x >= 'M' && x <= 'O')	return '6';
	else if(x >= 'P' && x <= 'S')	return '7';
	else if(x >= 'T' && x <= 'V')	return '8';
	else							return '9';
}

int main() {

	int i,n;

	while(gets(s) != NULL) {
		n = strlen(s);
		for(i=0;i<n;i++) 
			if(s[i] >= 'A' && s[i] <= 'Z')
				s[i] = trans(s[i]);
		puts(s);
	}
	
	return 0;
}
