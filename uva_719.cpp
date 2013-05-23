#include <stdio.h>
#include <string.h>

int n,m;
char str[20010];

int main() {

	int t;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%s",str);
		n = strlen(str);
		for(int i=0;i<n;++i)
			str[n+i] = str[i];
		
		int min= 0;
		int i=0,j=1;
		while(i < n && j < n) {
			bool yes=false;
			for(int k=0;k<n;++k) {
				if(str[i+k] > str[j+k]) {
					min = i = j;
					j = i+1;
					yes = true;
					break;
				} else if(str[i+k] < str[j+k]) {
					if(k == 0)	++j;
					else		j+=k;
					yes = true;
					break;
				}
			}
			if(!yes)	i+=n, j+=n;
		}
		
		printf("%d\n",min+1);
	}

	return 0;
}
