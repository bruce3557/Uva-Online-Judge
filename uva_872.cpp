#include <stdio.h>
#include <string.h>
#include <algorithm>

int n;
char list[1000];
char name[30];
bool map[30][30];
char temp[30];
char used[30];

int find(char cha) {
	for(int i=0;i<n;++i)
		if(name[i] == cha)
			return i;
	return -1;
}

void go(int now) {
	if(now >= n) {
		for(int i=0;i<n-1;++i)
			printf("%c ",temp[i]);
		printf("%c\n",temp[n-1]);
		return;
	}
	for(int i=0;i<n;++i)
		if(map[i][j] == 0)
}

int main() {
	int t;
	int c=0;
	
	scanf("%d",&t);
	while(t--) {
		if(c)	puts("");
		else	c=1;
		gets(list);
		n = 0;
		int len = strlen(list);
		for(int i=0;i<len;++i)
			if(list[i] != ' ')
				name[n++] = list[i];
		memset(map,0,sizeof(map));
		std::sort(name,name+n);
		gets(list);
		len = list;
		int i=0;
		while(i < len) {
			if(list[i] == ' ') { ++i;	continue; }
			int a=find(list[i]);
			int b=find(list[i+2]);
			map[a][b] = 1;
		}
		memset(used,0,sizeof(used));
		go(0);
	}
	
	return 0;
}
