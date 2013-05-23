#include <stdio.h>
#include <string.h>

int s[3010];
char abss[3010];

int abs(int x){
	if(x < 0)	return -x;
	return x;
}

int main() {
	int n,i;
	
	while(scanf("%d",&n) != EOF) {
		memset(abss,0,sizeof(char)*(n+1));
		for(i=0;i<n;i++)
			scanf("%d",&s[i]);
		for(i=0;i<n-1;i++)
			abss[abs(s[i]-s[i+1])] = 1;
		for(i=1;i<n && abss[i];i++);
		if(i < n)
			puts("Not jolly");
		else
			puts("Jolly");
	}
	
	return 0;
}
