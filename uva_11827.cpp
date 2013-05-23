#include <stdio.h>
#include <string.h>

int n;
int s[1010];
char str[10010];

int GCD(int a, int b) {
	if(b == 0)	return a;
	return GCD(b, a%b);
}

int main() {
	int t;
	
	scanf("%d",&t);
	gets(str);
	while(t--) {
		gets(str);
		char *ptr = strtok(str, " \n\0");
		n = 0;
		while( ptr != NULL) {
			sscanf(ptr,"%d",s+n);
			ptr = strtok(NULL, " \n\0");
			++n;
		}
		int maxi = 1;
		for(int i=0;i<n;++i)
			for(int j=0;j<i;++j) {
				int x = GCD(s[i],s[j]);
				if(x > maxi)	maxi = x;
			}
		printf("%d\n",maxi);
	}
	return 0;
}
