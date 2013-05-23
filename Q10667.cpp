#include <stdio.h>

int map[110][110];

int main() {
	
	int t,i,j,k;
	int n,m,w,area,h;
	int x1,x2,y1,y2;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				map[i][j] = 1;
				
		while(m--) {
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			for(i=x1;i<=x2;i++)
				for(j=y1;j<=y2;j++)
					map[i][j] = 0;
		}
		
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(map[i][j])
					map[i][j] += map[i][j-1];
		
		area = 0;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++) {
				w = 999999999;
				for(k=1;i-k >= 0;k++) {
					if(map[i-k+1][j] == 0)	break;
					if(w > map[i-k+1][j])
						w = map[i-k+1][j];
					if(area < w*k)
						area = w*k;
				}
			}
		
		printf("%d\n",area);
	}
	
	return 0;
}
