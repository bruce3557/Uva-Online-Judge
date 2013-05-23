#include <stdio.h>
#include <string.h>

struct node {
	int x,y,cnt;
} q[100010];

int n,min;
char map[110][110],used[110][110],cnt;

int Max(int a,int b) {
	return a > b ? a : b;
}

int Min(int a,int b) {
	return a < b ? a : b;
}

int go(int x,int y) {
	int i,j,a,b;
	q[0] = (node){x,y,0};
	memset(used,0,sizeof(used));
	i = 0, j = 1;
	used[x][y] = 1;
	while(i < j) {
		a = q[i].x, b = q[i].y;
		if(map[a][b] == '3')	return q[i].cnt;
		if(a-1 >= 0 && used[a-1][b] == 0) {
			used[a-1][b] = 1;
			q[j++] = (node){a-1,b,q[i].cnt+1};
		}
		if(b-1 >= 0 && used[a][b-1] == 0) {
			used[a][b-1] = 1;
			q[j++] = (node){a,b-1,q[i].cnt+1};
		}
		if(a+1 < n && used[a+1][b] == 0) {
			used[a+1][b] = 1;
			q[j++] = (node){a+1,b,q[i].cnt+1};
		}
		if(b+1 < n && used[a][b+1] == 0) {
			used[a][b+1] = 1;
			q[j++] = (node){a,b+1,q[i].cnt+1};
		}
		i++;
	}
	return 0;
}

int main() {
	int i,j,ans;
	
	while(scanf("%d",&n) != EOF) {
		for(i=0;i<n;i++)
			scanf("%s",map[i]);
		
		for(i=ans=0;i<n;i++)
			for(j=0;j<n;j++)
				if(map[i][j] == '1')
					ans = Max(go(i,j),ans);
		
		printf("%d\n",ans);
	}
	
	return 0;
}
