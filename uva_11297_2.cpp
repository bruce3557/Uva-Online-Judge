#include <stdio.h>
#include <string.h>

int n,m;
int map[510][510];

inline int Max(int a, int b) {
	return (a > b) ? a : b;
}

inline int Min(int a, int b) {
	return (a < b) ? a : b;
}

int main() {
	
	while(scanf("%d%d",&n,&m) != EOF) {
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				scanf("%d",&map[i][j]);
		
		int Q;
		scanf("%d",&Q);
		while(Q--) {
			char op[5];
			scanf("%s",op);
			if(op[0] == 'q') {
				int x1, y1, x2, y2;
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				/*
				if(x1 > x2)	{
					int temp = x1;
					x1 = x2;
					x2 = temp;
				}
				if(y1 > y2) {
					int temp = y1;
					y1 = y2;
					y2 = temp;
				}
				*/
				
				int maxi, mini;
				maxi = 0;
				mini = 999999999;
				for(int i=x1;i<=x2;++i)
					for(int j=y1;j<=y2;++j) {
						maxi = Max(maxi, map[i][j]);
						mini = Min(mini, map[i][j]);
					}
				printf("%d %d\n",maxi,mini);
			} else {
				int x, y, value;
				scanf("%d%d%d",&x, &y, &value);
				map[x][y] = value;
			}
		}
	}

	return 0;
}
