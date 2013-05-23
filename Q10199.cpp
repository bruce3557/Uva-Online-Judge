#include <stdio.h>
#include <string.h>
#include <algorithm>

int n,m;
char used[110],ans[110];
int map[110][110],ori[110][110];

struct node {
	char s[50];
	bool operator < (node t) const {
		return strcmp(s,t.s) < 0;
	}
}name[110];

void go(int now) {
	used[now] = 1;
	for(int i=0;i<n;i++)
		if(used[i] == 0 && map[now][i])
			go(i);
}

int main() {
	int i,j,k,l,cnt,counter,count;
	int c = 0;
	char s[50],t[50];
	
	while(scanf("%d",&n) && n) {
		if(c)	puts("");
		memset(map,0,sizeof(map));
		memset(ans,0,sizeof(ans));
		memset(ori,0,sizeof(ori));
		for(i=0;i<n;i++)
			scanf("%s",name[i].s);
		std::sort(name,name+n);
		scanf("%d",&m);
		while(m--) {
			scanf("%s%s",s,t);
			for(i=0;i<n;i++)
				if(strcmp(s,name[i].s) == 0)
					break;
			for(j=0;j<n;j++)
				if(strcmp(t,name[j].s) == 0)
					break;
			map[i][j] = map[j][i] = ori[i][j] = ori[j][i] = 1;
		}
		
		memset(used,0,sizeof(used));
		count = cnt = 0;
		for(i=0;i<n;i++)
			if(used[i] == 0) {
				count++;
				go(i);
			}
		
		for(i=0;i<n;i++) {
			memset(used,0,sizeof(used));
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					map[j][k] = ori[j][k];
			for(j=0;j<n;j++)
				map[i][j] = map[j][i] = 0;
			counter = 0;
			for(j=0;j<n;j++)
				if(j != i && used[j] == 0) {
					counter++;
					go(j);
				}
			if(counter > count) {
				cnt++;
				ans[i] = 1;
			}
		}
		
		printf("City map #%d: %d camera(s) found\n",++c,cnt);
		for(i=0;i<n;i++)
			if(ans[i])
				puts(name[i].s);
	}
	
	return 0;
}
