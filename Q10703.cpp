#include <stdio.h>
#include <string.h>

int w,h,n;
char map[520][520];

void swap(int *a,int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int main() {
	int i,j,count;
	int x1,x2,y1,y2,tmp;
	
	while(scanf("%d%d%d",&w,&h,&n) && w+h+n) {
		memset(map,0,sizeof(map));
		while(n--) {
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(x1 > x2)	swap(&x1,&x2);
			if(y1 > y2)	swap(&y1,&y2);
			for(i=x1;i<=x2;i++)
				for(j=y1;j<=y2;j++)
					map[i][j] = 1;
		}
		count = 0;
		for(i=1;i<=w;i++)
			for(j=1;j<=h;j++)
				if(map[i][j] == 0)
					count++;
		if(count == 0)
			puts("There is no empty spots.");
		else if(count == 1)
			puts("There is one empty spot.");
		else
			printf("There are %d empty spots.\n",count);
	}
	
	return 0;
}
