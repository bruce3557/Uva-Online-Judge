#include <stdio.h>
#includd <string.h>

char name[50],direct;

struct node {
    int x,y;
    char dir[10];
} map[20][20][10];

char used[20][20][10];

struct d {
    int x,y,pre;
    char dir;
} st,ed,q[1000000];

void print(int now) {
	if(now == -1)	return;
	print(q[now].pre);
	printf("(%d, %d) ",q[now].x,q[now].y);
}

int main() {

    int i,j,k;
	int tmpx,tmpy;
	char tmpd,tmp[10],tt;

    while(gets(name)) {
        if(strcmp(name,"END") == 0) break;
        memset(used,0,sizeof(used));
		
		scanf("%d %d %c %d %d",&st.x,&st.y,&st.dir,&ed,x,&ed.y);
        
		while(scanf("%d",&i) && i) {
            scanf("%d",&j);
			scanf("%s",tmp);
			if(tmp[0] == '*')	continue;
			if(tmp[0] == 'N') {
				for(k=1;tmp[k] != '\0';k++)
					map[i][j][0].dir[k-1] = tmp[k];
				map[i][j][0].dir[k-1] = '\0';
			} else if(tmp[0] == 'S') {
				for(k=1;tmp[k] != '\0';k++)
					map[i][j][1].dir[k-1] = tmp[k];
				map[i][j][1].dir[k-1] = '\0';
			} else if(tmp[0] == 'E') {
				for(k=1;tmp[k] != '\0';k++)
					map[i][j][2].dir[k-1] = tmp[k];
				map[i][j][2].dir[k-1] = '\0';
			} else {
				for(k=1;tmp[k] != '\0';k++)
					map[i][j][3].dir[k-1] = tmp[k];
				map[i][j][3].dir[k-1] = tmp[k];
			}
			scanf("%s",tmp);
			if(tmp[0] == '*')	continue;
			if(tmp[0] == 'N') {
				for(k=1;tmp[k] != '\0';k++)
					map[i][j][0].dir[k-1] = tmp[k];
				map[i][j][0].dir[k-1] = '\0';
			} else if(tmp[0] == 'S') {
				for(k=1;tmp[k] != '\0';k++)
					map[i][j][1].dir[k-1] = tmp[k];
				map[i][j][1].dir[k-1] = '\0';
			} else if(tmp[0] == 'E') {
				for(k=1;tmp[k] != '\0';k++)
					map[i][j][2].dir[k-1] = tmp[k];
				map[i][j][2].dir[k-1] = '\0';
			} else {
				for(k=1;tmp[k] != '\0';k++)
					map[i][j][3].dir[k-1] = tmp[k];
				map[i][j][3].dir[k-1] = tmp[k];
			}
			scanf("%s",tmp);
			if(tmp[0] == '*')	continue;
			if(tmp[0] == 'N') {
				for(k=1;tmp[k] != '\0';k++)
					map[i][j][0].dir[k-1] = tmp[k];
				map[i][j][0].dir[k-1] = '\0';
			} else if(tmp[0] == 'S') {
				for(k=1;tmp[k] != '\0';k++)
					map[i][j][1].dir[k-1] = tmp[k];
				map[i][j][1].dir[k-1] = '\0';
			} else if(tmp[0] == 'E') {
				for(k=1;tmp[k] != '\0';k++)
					map[i][j][2].dir[k-1] = tmp[k];
				map[i][j][2].dir[k-1] = '\0';
			} else {
				for(k=1;tmp[k] != '\0';k++)
					map[i][j][3].dir[k-1] = tmp[k];
				map[i][j][3].dir[k-1] = tmp[k];
			}
			scanf("%s",tmp);
			if(tmp[0] == '*')	continue;
			if(tmp[0] == 'N') {
				for(k=1;tmp[k] != '\0';k++)
					map[i][j][0].dir[k-1] = tmp[k];
				map[i][j][0].dir[k-1] = '\0';
			} else if(tmp[0] == 'S') {
				for(k=1;tmp[k] != '\0';k++)
					map[i][j][1].dir[k-1] = tmp[k];
				map[i][j][1].dir[k-1] = '\0';
			} else if(tmp[0] == 'E') {
				for(k=1;tmp[k] != '\0';k++)
					map[i][j][2].dir[k-1] = tmp[k];
				map[i][j][2].dir[k-1] = '\0';
			} else {
				for(k=1;tmp[k] != '\0';k++)
					map[i][j][3].dir[k-1] = tmp[k];
				map[i][j][3].dir[k-1] = '\0';
			}
        }
		
		q[0] = st;
		q[0].pre = -1;
		i = 0;
		j = 1;
		while(i < j) {
			tmpx = q[i].x;
			tmpy = q[i].y;
			tmpd = q[i].dir;
			if(tmpx == ed.x && tmpy == ed.y)	break;
			if(tmpd == 'N') {
				for(k=0;map[tmpx][tmpy][0].dir[k] != '\0';k++) {
					tt = map[tmpx][tmpy][0].dir[k];
					if(tt == 'L') {
						if(tmpy-1 >=1 && used[tmpx][tmpy-1][3] == 0) {
							used[tmpx][tmpy-1][2] = 1;
							q[j++] = (d){tmpx,tmpy-1,i,'W'};
						}
					} else if(tt == 'F') {
						if(tmpx-1 >= 1 && used[tmpx-1][tmpy][0] == 0) {
							used[tmpx-1][tmpy][0] = 1;
							q[j++] = (d){tmpx-1,tmpy,i,'N'};
						}
					} else {
						if(tmpy+1 <=9 && used[tmpx][tmpy+1][2] == 0) {
							used[tmpx][tmpy+1][2] = 1;
							q[j++] = (d){tmpx,tmpy+1,i,'E'};
						}
					}
				}
			} else if(tmpd == 'E') {
				for(k=0;map[tmpx][tmpy][2].dir[k] != '\0';k++) {
					tt = map[tmpx][tmpy][2].dir[k];
					if(tt == 'L') {
						if(tmpx-1 >=1 && used[tmpx-1][tmpy][0] == 0) {
							used[tmpx-1][tmpy][2] = 1;
							q[j++] = (d){tmpx-1,tmpy,i,'N'};
						}
					} else if(tt == 'F') {
						if(tmpy+1 <= 9 && used[tmpx-1][tmpy][0] == 0) {
							used[tmpx-1][tmpy][0] = 1;
							q[j++] = (d){tmpx-1,tmpy,i,'E'};
						}
					} else {
						if(tmpy+1 <=9 && used[tmpx][tmpy+1][2] == 0) {
							used[tmpx][tmpy+1][2] = 1;
							q[j++] = (d){tmpx,tmpy+1,i,'W'};
						}
					}
				}
			} else if(tmpd == 'W') {
				
			} else {
				
			}
		}
		
		puts(name);
		if(i >= j)
			puts("  No Solution Possible");
		else
			print(i);
    }

    return 0;
}
