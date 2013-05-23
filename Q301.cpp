#include <stdio.h>
#include <string.h>

struct node {
	int a,b,c;
} edge[25];

int des,total[25],max,m,n;

void go(int now) {
	if(now >= m) {
		int sum = 0;
		for(int i=0;i<=des;i++)
			sum += total[i];
		if(sum > max)
			max = sum;
		return;
	}
	
	//¨ú
	char flag = 0;
	for(int i=edge[now].a+1;i<=edge[now].b;i++)
		if(total[i]+edge[now].c > n) {
			flag = 1;
			break;
		}
	if(flag == 0) {
		for(int i=edge[now].a+1;i<=edge[now].b;i++)
			total[i] += edge[now].c;
		go(now+1);
		for(int i=edge[now].a+1;i<=edge[now].b;i++)
			total[i] -= edge[now].c;
	}
	
	//¤£¨ú
	go(now+1);
	
}

int main() {
	
	while(scanf("%d%d%d",&n,&des,&m) && n+des+m) {
		memset(total,0,sizeof(total));
		for(int i=0;i<m;i++)
			scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);
		max = 0;
		go(0);
		printf("%d\n",max);
	}
	
	return 0;
}
