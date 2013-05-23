#include <stdio.h>
#include <string.h>
#include <queue>
using std::queue;

int dx[]={-1,-1,0,1,1,0};
int dy[]={1,0,-1,-1,0,1};

struct node {
	int x,y;
}pt[10010];

int edge[10010][10];
bool used[10010];

void Build() {
	pt[1] = (node){0,0};
	pt[2] = (node){-1,1};
	pt[3] = (node){-1,0};
	pt[4] = (node){0,-1};
	pt[5] = (node){1,-1};
	pt[6] = (node){1,0};
	pt[7] = (node){0,1};
	int id=8;
	for(int i=2;;++i) {
		pt[id] = (node){pt[id-1].x-1,pt[id-1].y+1};
		id++;
		for(int j=0;j<i-1;++j) {
			pt[id] = (node){pt[id-1].x-1,pt[id-1].y};
			id++;
			if(id > 10000)	break;
		}
		if(id > 10000)	break;

		//left-up
		for(int j=0;j<i;++j) {
			pt[id] = (node){pt[id-1].x,pt[id-1].y-1};
			id++;
			if(id > 10000)	break;
		}
		if(id > 10000)	break;

		//up
		for(int j=0;j<i;++j) {
			pt[id] = (node){pt[id-1].x+1,pt[id-1].y-1};
			id++;
			if(id > 10000)	break;
		}
		if(id > 10000)	break;

		//right-up
		for(int j=0;j<i;++j) {
			pt[id] = (node){pt[id-1].x+1,pt[id-1].y};
			id++;
			if(id > 10000)	break;
		}
		if(id > 10000)	break;

		//right-down
		for(int j=0;j<i;++j) {
			pt[id] = (node){pt[id-1].x,pt[id-1].y+1};
			id++;
			if(id > 10000)	break;
		}
		if(id > 10000)	break;
		
		//down
		for(int j=0;j<i;++j) {
			pt[id] = (node){pt[id-1].x-1,pt[id-1].y+1};
			id++;
			if(id > 10000)	break;
		}
		if(id > 10000)	break;
	}
	
	
	for(int i=1;i<=10000;++i) {
		for(int j=0;j<6;++j) {
			for(int k=(i-1000>0)?(i-1000):1;k<=i+1000;++k)
				if((pt[i].x+dx[j]) == pt[k].x && (pt[i].y+dy[j]) == pt[k].y) {
					edge[i][j] = k;
					break;
				}
		}
	}
	
}

int main() {

	Build();
	int a,b;
	while(scanf("%d%d",&a,&b) && a+b) {
		memset(used,0,sizeof(used));
		used[a] = 1;
		queue< node > Q;
		Q.push((node){a,0});
		int ans=0;
		while( !Q.empty() ) {
			node tp = Q.front();
			if(tp.x == b) {
				ans = tp.y;
				break;
			}
			//puts("jizz");
			for(int i=0;i<6;++i) {
				//printf("%d ",edge[tp.x][i]);
				if(edge[tp.x][i] <= 10000 && edge[tp.x][i] > 0 && !used[edge[tp.x][i]]) {
					used[edge[tp.x][i]] = 1;
					Q.push((node){edge[tp.x][i],tp.y+1});
				}
			}
			//puts("");
			Q.pop();
		}
		printf("The distance between cells %d and %d is %d.\n",a,b,ans);
	}
	
	return 0;
}
