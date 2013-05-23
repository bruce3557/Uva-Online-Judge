#include <stdio.h>
#include <string.h>
#include <queue>
using std::queue;

int num;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2,-2,-1, 1, 2,  2,  1};
char used[10][10][1<<10][100];
char map[10][10];
struct node {
	int x,y;
	int step,count,state;
}Pawn[10];

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&num);
		memset(used,0,sizeof(used));
		for(int i=0;i<8;i++)
			scanf("%s",map[i]);
		
		int cnt = 0;
		node first;
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++) {
				if(map[i][j] == 'K') {
					for(int k=0;k<(1<<10);k++)
						for(int q=0;q<100;q++)
						used[i][j][k][q] = 1;
				} else if(map[i][j] == 'k') {
					first.x = i;
					first.y = j;
				} else if(map[i][j] == 'P') {
					Pawn[cnt].x = i;
					Pawn[cnt].y = j;
					cnt++;
				} else if(map[i][j] == 'p') {
					for(int k=0;k<(1<<10);k++)
						for(int q=0;q<100;q++)
							used[i][j][k][q] = 1;
				}
			}
			
		first.step = 0;
		first.state = 0;
		first.count = cnt;
		used[first.x][first.y][0][0] = 1;
		
		bool flag = false;
		queue< node > Q;
		Q.push(first);
		while( !Q.empty() ) {
			node tmp = Q.front();
			Q.pop();
			if(tmp.count == 0) {
				flag = true;
				break;
			}
			if(tmp.step >= num)	continue;
			for(int i=0;i<8;i++)
				if(tmp.x+dx[i] >= 0 && tmp.x+dx[i] < 8 && tmp.y+dy[i] >= 0 && tmp.y+dy[i] < 8 ) {
					node next;
					next.x = tmp.x+dx[i];
					next.y = tmp.y+dy[i];
					next.step = tmp.step+1;
					if(map[next.x][next.y] == 'P') {
						int j;
						for(j=0;j<cnt;j++)
							if(Pawn[j].x == next.x && Pawn[j].y == next.y)
								break;
						int next_v = tmp.state | (1<<j);
						if(!(tmp.state&(1<<j))) {
							if(!used[next.x][next.y][next_v][next.step]) {
								next.count = tmp.count-1;
								next.state = next_v;
								used[next.x][next.y][next_v][next.step] = 1;
								Q.push(next);
							}
						} else {
							if(!used[next.x][next.y][next_v][next.step]) {
								next.count = tmp.count;
								next.state = next_v;
								used[next.x][next.y][next_v][next.step] = 1;
								Q.push(next);
							}
						}
					} else {
						int next_v = tmp.state;
						if(!used[next.x][next.y][next_v][next.step]) {
							next.count = tmp.count;
							next.state = next_v;
							used[next.x][next.y][next_v][next.step] = 1;
							Q.push(next);
						}
					}
				}
		}
		
		if( !flag )
			puts("No");
		else
			puts("Yes");
	}

	return 0;
}
