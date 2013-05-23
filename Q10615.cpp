#include <stdio.h>
#include <string.h>

int n,color[110][110];
char grid[50][50],map[110][110];

int main() {
	int t,i,j;
	
	scanf("%d",&t);
	while(t--) {
		memset(map,0,sizeof(map));
		memset(color,0,sizeof(color));
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s",grid[i]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(grid[i][j] == '*')
					map[i][j+n+1] = 1;
				else
					
	}
	
	return 0;
}
