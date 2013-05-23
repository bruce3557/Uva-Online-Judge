#include <stdio.h>
#include <string.h>
struct node{
	int x,y,cnt;
}st,ed,q[10000];
char s[5][5],used[10][10];
int n = 8;
int main(){
	int i,j,x,y;
	while(scanf("%s %s",s[0],s[1]) != EOF){
		st = (node){s[0][0]-'a',s[0][1]-'1'};
		ed = (node){s[1][0]-'a',s[1][1]-'1'};
		memset(used,0,sizeof(used));
		q[0] = st, q[0].cnt = 0;
		used[q[0].x][q[0].y] = 1;
		for(i=0,j=1;i<j;i++){
			x = q[i].x, y =q[i].y;
			
			if(x == ed.x && y == ed.y)	break;
		
			if(x-1 >= 0 && y-2 >= 0 && used[x-1][y-2] == 0){
				used[x-1][y-2] = 1;
				q[j++] = (node){x-1,y-2,q[i].cnt+1};
			}
		
			if(x-2 >= 0 && y-1 >= 0 && used[x-2][y-1] == 0){
				used[x-2][y-1] = 1;
				q[j++] = (node){x-2,y-1,q[i].cnt+1};
			}
		
			if(x-1 >= 0 && y+2 < 8 && used[x-1][y+2] == 0){
				used[x-1][y+2] = 1;
				q[j++] = (node){x-1,y+2,q[i].cnt+1};
			}
		
			if(x-2 >= 0 && y+1 < 8 && used[x-2][y+1] == 0){
				used[x-2][y+1] = 1;
				q[j++] = (node){x-2,y+1,q[i].cnt+1};
			}
		
			if(x+1 <8 && y-2 >= 0 && used[x+1][y-2] == 0){
				used[x+1][y-2] = 1;
				q[j++] = (node){x+1,y-2,q[i].cnt+1};
			}
		
			if(x+2 < 8 && y-1 >= 0 && used[x+2][y-1] == 0){
				used[x+2][y-1] = 1;
				q[j++] = (node){x+2,y-1,q[i].cnt+1};
			}
		
			if(x+1 < 8 && y+2 < 8 && used[x+1][y+2] == 0){
				used[x+1][y+2] = 1;
				q[j++] = (node){x+1,y+2,q[i].cnt+1};
			}
		
			if(x+2 < 8 && y+1 < 8 && used[x+2][y+1] == 0){
				used[x+2][y+1] = 1;
				q[j++] = (node){x+2,y+1,q[i].cnt+1};
			}
		
		}
		
		printf("To get from %s to %s takes %d knight moves.\n",s[0],s[1],q[i].cnt);
	}
	return 0;
}
