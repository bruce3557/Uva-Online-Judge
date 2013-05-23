#include <stdio.h>

int n,map[110][110];

bool check() {
	int i,j,count;
	for(i=1;i<=n;i++) {
		count = 0;
		for(j=1;j<=n;j++)
			count += map[i][j];
		if(count % 2)	return 1;
	}
	for(i=1;i<=n;i++) {
		count = 0;
		for(j=1;j<=n;j++)
			count += map[j][i];
		if(count % 2)	return 1;
	}
	return 0;
}

int main() {
	int i,j,a,b;
	
	while(scanf("%d",&n) && n) {
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&map[i][j]);
		a = check();
		if(a == 0) {
			puts("OK");
		} else {
			for(i=1;i<=n;i++) {
				for(j=1;j<=n;j++) {
					map[i][j] = 1-map[i][j];
					b = check();
					if(b == 0)	{
						printf("Change bit (%d,%d)\n",i,j);
						break;
					}
					map[i][j] = 1-map[i][j];
				}
				if(j <= n)	break;
			}
			if(i > n)	puts("Corrupt");
		}
	}
	
	return 0;
}
