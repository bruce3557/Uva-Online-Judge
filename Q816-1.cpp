#include <stdio.h>
#include <string.h>

char map[20][20][6][6];
char used[20][20][6];

struct node {
	int x,y,pre;
	char dir;
} st,ed,q[1000010],ans[1000010];

int main() {

	int i,j,k,tx,ty;
	char name[100];
	char tmp[100],td,d;

	while(gets(name) && strcmp(name,"END") != 0) {
		memset(used,0,sizeof(used));
		memset(map,0,sizeof(map));
		scanf("%d %d %c %d %d",&st.x,&st.y,&st.dir,&ed.x,&ed.y);
		
		while(scanf("%d",&i) && i) {
			scanf("%d",&j);
			while(scanf("%s",tmp) && tmp[0] != '*') {
				if(tmp[0] == 'N') {
					for(k=1;tmp[k];k++)
						map[i][j][0][k-1] = tmp[k];
					map[i][j][0][k-1] = '\0';
				} else if(tmp[0] == 'E') {
					for(k=1;tmp[k];k++)
						map[i][j][1][k-1] = tmp[k];
					map[i][j][1][k-1] = '\0';
				} else if(tmp[0] == 'W') {
					for(k=1;tmp[k];k++)
						map[i][j][2][k-1] = tmp[k];
					map[i][j][2][k-1] = '\0';
				} else {
					for(k=1;tmp[k];k++)
						map[i][j][3][k-1] = tmp[k];
					map[i][j][3][k-1] = '\0';
				}
			}
		}
		
		q[0] = st;
		q[0].pre = -1;
		if(q[0].dir == 'N') {
			used[q[0].x-1][q[0].y][0] = 1;
			q[1] = (node){q[0].x-1,q[0].y,0,'N'};
		} else if(q[0].dir == 'E') {
			used[q[0].x][q[0].y+1][1] = 1;
			q[1] = (node){q[0].x,q[0].y+1,0,'E'};
		} else if(q[0].dir == 'W') {
			used[q[0].x][q[0].y-1][2] = 1;
			q[1] = (node){q[0].x,q[0].y-1,0,'W'};
		} else {
			used[q[0].x+1][q[0].y][3] = 1;
			q[1] = (node){q[0].x+1,q[0].y,0,'S'};
		}
		
		i=1,j=2;
		while(i < j) {
			tx = q[i].x;
			ty = q[i].y;
			td = q[i].dir;
			if(tx == ed.x && ty == ed.y)	break;
			if(td == 'N') {
				for(k=0;map[tx][ty][0][k];k++) {
					d = map[tx][ty][0][k];
					if(d == 'L') {
						if(ty-1 >= 1 && used[tx][ty-1][2] == 0) {
							used[tx][ty-1][2] = 1;
							q[j++] = (node){tx,ty-1,i,'W'};
						}
					} else if(d == 'F') {
						if(tx-1 >= 1 && used[tx-1][ty][0] == 0) {
							used[tx-1][ty][0] = 1;
							q[j++] = (node){tx-1,ty,i,'N'};
						}
					} else {
						if(ty+1 <= 9 && used[tx][ty+1][1] == 0) {
							used[tx][ty+1][1] = 1;
							q[j++] = (node){tx,ty+1,i,'E'};
						}
					}
				}
			} else if(td == 'E') {
				for(k=0;map[tx][ty][1][k];k++) {
					d = map[tx][ty][1][k];
					if(d == 'L') {
						if(tx-1 >= 1 && used[tx-1][ty][0] == 0) {
							used[tx-1][ty][0] = 1;
							q[j++] = (node){tx-1,ty,i,'N'};
						}
					} else if(d == 'F') {
						if(ty+1 <= 9 && used[tx][ty+1][1] == 0) {
							used[tx][ty+1][1] = 1;
							q[j++] = (node){tx,ty+1,i,'E'};
						}
					} else {
						if(tx+1 <= 9 && used[tx+1][ty][3] == 0) {
							used[tx+1][ty][3] = 1;
							q[j++] = (node){tx+1,ty,i,'S'};
						}
					}
				}
			} else if(td == 'W') {
				for(k=0;map[tx][ty][2][k];k++) {
					d = map[tx][ty][2][k];
					if(d == 'L') {
						if(tx+1 <= 9 && used[tx+1][ty][3] == 0) {
							used[tx+1][ty][3] = 1;
							q[j++] = (node){tx+1,ty,i,'S'};
						}
					} else if(d == 'F') {
						if(ty-1 >= 1 && used[tx][ty-1][2] == 0) {
							used[tx][ty-1][2] = 1;
							q[j++] = (node){tx,ty-1,i,'W'};
						}
					} else {
						if(tx-1 >= 1 && used[tx-1][ty][0] == 0) {
							used[tx-1][ty][0] = 1;
							q[j++] = (node){tx-1,ty,i,'N'};
						}
					}
				}
			} else {
				for(k=0;map[tx][ty][3][k];k++) {
					d = map[tx][ty][3][k];
					if(d == 'L') {
						if(ty+1 <= 9 && used[tx][ty+1][1] == 0) {
							used[tx][ty+1][1] = 1;
							q[j++] = (node){tx,ty+1,i,'E'};
						}
					} else if(d == 'F') {
						if(tx+1 <= 9 && used[tx+1][ty][3] == 0) {
							used[tx+1][ty][3] = 1;
							q[j++] = (node){tx+1,ty,i,'S'};
						}
					} else {
						if(ty-1 >= 1 && used[tx][ty-1][2] == 0) {
							used[tx][ty-1][2] = 1;
							q[j++] = (node){tx,ty-1,i,'W'};
						}
					}
				}
			}
			i++;
		}
		
		puts(name);
		if(i >= j) {
			puts("  No Solution Possible");
		} else {
			k = 0;
			for(k=0;i!=-1;i=q[i].pre,k++)
				ans[k] = q[i];
			for(j=1;j<=k;j++) {
				if(j%10 == 1)	printf(" ");
				printf(" (%d,%d)",ans[k-j].x,ans[k-j].y);
				if(j%10 == 0)	puts("");
			}
			if((j-1)%10)	puts("");
		}
		getchar();
	}
	
	return 0;
}
