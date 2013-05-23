#include <stdio.h>
#include <algorithm>

int len,ans[5000],n,st[50],deg[50];
char used[5000];

struct node{
	int x,y,z;
	bool operator < (node t) const {
		return (x<t.x || (x==t.x && z<t.z));
	}
}edge[5000];

void go(int now){
	for(int i = st[now];i < st[now+1];i++)
		if(used[edge[i].z] == 0){
			used[edge[i].z] = 1;
			go(edge[i].y);
			ans[len++] = edge[i].z;
		}
}

int main(){
	int i,c=0,flag,st1;
	while(scanf("%d%d",&edge[0].x,&edge[0].y) && edge[0].x+edge[0].y){
		scanf("%d",&edge[0].z);
		edge[1] = (node){edge[0].y,edge[0].x,edge[0].z};
		n = 2;
		
		if(edge[0].x < edge[0].y){
			st1 = edge[0].x;
		} else {
			st1 = edge[0].y;
		}
		memset(deg,0,sizeof(deg));
		deg[edge[0].x]++;
		deg[edge[0].y]++;

		while(1){
			scanf("%d%d",&edge[n].x,&edge[n].y);
			if(edge[n].x == 0 && edge[n].y == 0)	break;
			scanf("%d",&edge[n].z);
			deg[edge[n].x]++;
			deg[edge[n].y]++;
			n++;
			edge[n] = (node){edge[n-1].y,edge[n-1].x,edge[n-1].z};
			n++;
		}

		for(i=0;i<50;i++)
			if(deg[i] & 1)
				break;
		if(i < 50){
			puts("Round trip does not exist.\n");
			continue;
		}

		std::sort(edge,edge+n);
		len = 0;
		
		for(i=0;i<50;i++)
			st[i] = -1;
		for(i=0;i<n;i++)
			if(st[edge[i].x] == -1)
				st[edge[i].x] = i;
		st[edge[n-1].x+1] = n;
		
		memset(used,0,sizeof(used));
		for(i=0;i<n;i++)
			if(edge[i].x == st1){
				go(st1);
				break;
			}
				
		if(len != n/2){
			puts("Round trip does not exist.\n");
			continue;
		}

		for(i=len-1;i>0;i--)
			printf("%d ",ans[i]);
		printf("%d\n\n",ans[i]);

	}
	return 0;
}
