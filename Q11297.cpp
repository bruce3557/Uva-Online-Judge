#include <stdio.h>
#define MAX 2147483647

int map[510][510];

int main() {

	int n,m,action_num,min,max;
	int i,j;
	int x1,x2,y1,y2,change;
	char action;
	
		scanf("%d%d",&n,&m);
		
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				scanf("%d",&map[i][j]);
		
		scanf("%d",&action_num);
		getchar();
		
		while(action_num--) {
		
			action = getchar();
			
			if(action == 'q') {
				
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				getchar();
				min = MAX;
				max = -MAX;
				for(i=x1;i<=x2;i++)
					for(j=y1;j<=y2;j++) {
						if(min > map[i][j])
							min = map[i][j];
						if(max < map[i][j])
							max = map[i][j];
					}
				printf("%d %d\n",max,min);
				
			} else if(action == 'c') {
				scanf("%d%d%d",&x1,&x2,&change);
				getchar();
				map[x1][x2] = change;
			}
		
		}
		
	//}

	return 0;
}
