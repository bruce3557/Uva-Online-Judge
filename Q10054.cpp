#include <stdio.h>
#include <string.h>

struct node{
	int a,b;
}ans[1010];

int n,deg[60],len,min,max;
char map[60][60];

void go(int now){
	for(int i=min;i<=max;i++)
		if(map[now][i]){
			map[now][i]--;
			map[i][now]--;
			go(i);
			ans[len++] = (node){now,i};
		}
}

int main(){
	int tt,i,j,k;
	int c = 0;
	scanf("%d",&tt);
	while(tt--){
		if(c)	puts("");
		scanf("%d",&n);
		k = len = 0;
		memset(deg,0,sizeof(int)*50);
		memset(map,0,sizeof(map));
		while(k < n){
			scanf("%d%d",&i,&j);
			deg[i]++;
			deg[j]++;
			map[i][j]++;
			map[j][i]++;
			k++;
		}
		for(i=0;i<=50 && deg[i] == 0;i++);
		min = i;
		for(i=50;i>=0 && deg[i] == 0;i--);
		max = i;
		for(i=min;i<=max;i++)
			if(deg[i] & 1)
				break;
		printf("Case #%d\n",++c);
		if(i<=max){
			puts("some beads may be lost");
			continue;
		}
		go(min);
		for(i=len-1;i>=0;i--)
			printf("%d %d\n",ans[i].a,ans[i].b);
	}
	return 0;
}
