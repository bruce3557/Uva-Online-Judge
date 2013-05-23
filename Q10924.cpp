#include <stdio.h>
#include <string.h>
#define MAX 20000

char notp[MAX+10];

int main() {
	
	char s[100];
	int i,j,k,n,sum;
	
	for(i=4;i<=MAX;i+=2)
		notp[i] = 1;
	for(i=9;i<=MAX;i+=3)
		notp[i] = 1;
	notp[0] = 1;

	for(i=5,k=2;i*i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			for(j = i*i;j <= MAX;notp[j] = 1,j+=i);
	
	while(gets(s) != NULL) {
		
		n = strlen(s);
		
		for(i=0;i<n;i++) {
			if(s[i] >= 'a' && s[i] <= 'z')
				s[i] = s[i]-'a'+1;
			else if(s[i] >= 'A' && s[i] <= 'Z')
				s[i] = s[i]-'A'+27;
		}
		
		for(i=sum=0;i<n;i++)
			sum += s[i];
			
		if(notp[sum] == 0)
			puts("It is a prime word.");
		else
			puts("It is not a prime word.");
		
	}
	
	return 0;
}
