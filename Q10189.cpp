#include <stdio.h>
#include <stdio.h>

int n,m;
char map[110][110],ans[110][110];

int check(int x,int y) {
	int counter = 0;
	if(x > 0) {
		if(y > 0 && map[x-1][y-1] == '*')
			counter++;
		if(map[x-1][y] == '*')
			counter++;
		if(y+1 < m && map[x-1][y+1] == '*')
			counter++;
	}
	if(y > 0 && map[x][y-1] == '*')
		counter++;
	if(y+1 < m && map[x][y+1] == '*')
		counter++;
	if(x+1 < n) {
		if(y > 0 && map[x+1][y-1] == '*')
			counter++;
		if(map[x+1][y] == '*')
			counter++;
		if(y+1 < m && map[x+1][y+1] == '*')
			counter++;
	}
	return counter;
}

int main() {
	int i,j,c=0;
	
	while(scanf("%d%d",&n,&m) && n+m) {
		if(c)	puts("");
		for(i=0;i<n;i++)
			scanf("%s",map[i]);
		
		printf("Field #%d:\n",++c);
		for(i=0;i<n;i++,puts(""))
			for(j=0;j<m;j++) {
				if(map[i][j] != '*')
					printf("%d",check(i,j));
				else
					printf("*");
			}
	}
	
	return 0;
}
