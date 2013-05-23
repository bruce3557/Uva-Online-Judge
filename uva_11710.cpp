#include <stdio.h>
#include <string.h>

int n,m;
int map[410][410],dis[410];
char name[410][20],used[410];

void Init() {
	for(int i=0;i<n;i++) {
		dis[i] = -1;
		used[i] = 0;
		for(int j=0;j<n;j++)
			map[i][j] = -1;
	}
}

int find(char *s) {
	for(int i=0;i<n;i++)
		if(strcmp(s,name[i]) == 0)
			return i;
	return -1;
}

int main() {
	int length;
	char t1[20],t2[20];

	while(scanf("%d %d",&n,&m) && n+m) {
		Init();
		for(int i=0;i<n;i++)
			scanf("%s",name[i]);
		for(int i=0;i<m;i++) {
			scanf("%s %s %d",t1,t2,&length);
			int a = find(t1);
			int b = find(t2);
			map[a][b] = map[b][a] = length;
		}
		scanf("%s",t1);
		int st = find(t1);
		
		dis[st] = 0;
		for(int i=0;i<n;i++) {
			int minptr = -1;
			for(int j=0;j<n;j++)
				if(used[j] == 0 && dis[j] != -1 && (minptr == -1 || dis[j] < dis[minptr]))
					minptr = j;	
			if(minptr == -1)	break;
			used[minptr] = 1;
			for(int j=0;j<n;j++)
				if(used[j] == 0 && map[minptr][j] != -1 && (dis[j] == -1 || dis[j] > map[minptr][j])) 
					dis[j] = map[minptr][j];
		}
		
		int sum = 0,i;
		for(i=0;i<n && dis[i] != -1;i++)
			if(i != st)
				sum += dis[i];
		
		if(i < n)	puts("Impossible");
		else	printf("%d\n",sum);
		
	}

	return 0;
}
