#include <stdio.h>
#include <string.h>
#define MAX (2147483647LL)

int n;
char s[210];
long long Max,sum;

int main() {
	int t,i,j;
	
	scanf("%d%*c",&t);
	while(t--) {
		gets(s);
		n = strlen(s);
		for(i=0;i<n;i++)
			s[i] -= '0';
		Max = 0;
		for(i=0;i<n;) {
			sum = 0;
			for(j=0;i < n && j < 10;i++,j++)
				sum = sum*10+s[i];
			if(sum > MAX)	sum /= 10,i--;
			Max += sum;
		}
		
		printf("%lld\n",Max);
	}
	
	return 0;
}
