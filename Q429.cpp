#include <stdio.h>
#include <string.h>

struct node {
	char s[20];
	int len;
} word[210];

struct gogo {
	int num,cnt;
}q[40010];

int n,st,ed;
char map[210][210],start[20],end[20],used[210];

int main() {
	int t,c=0;
	int i,j,k,diff;
	
	scanf("%d",&t);
	while(t--) {
		n = 0;
		while(scanf("%s",word[n].s) && word[n].s[0] != '*') {
			word[n].len = strlen(word[n].s);
			n++;
		}
		memset(map,0,sizeof(map));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++) {
				if(word[i].len != word[j].len)	continue;
				diff = 0;
				for(k=0;k<word[i].len;k++)
					if(word[i].s[k] != word[j].s[k])
						diff++;
				if(diff == 1)	map[i][j] = map[j][i] = 1;
			}
		if(c)	puts("");
		else	c = 1;
		char tmp;
		scanf("%*c");
		while(scanf("%c",&tmp) && tmp != '\n') {
			start[0] = tmp, i = 1;
			while(scanf("%c",&tmp) && tmp != ' ') {
				start[i] = tmp;
				i++;
			}
			start[i] = '\0';
			i = 0;
			while(scanf("%c",&tmp) && tmp != '\n') {
				end[i] = tmp;
				i++;
			}
			end[i] = '\0';
			for(i=0;i<n;i++)
				if(strcmp(start,word[i].s) == 0) {
					st = i;
					break;
				}
			for(i=0;i<n;i++)
				if(strcmp(end,word[i].s) == 0) {
					ed = i;
					break;
				}
			memset(used,0,sizeof(used));
			q[0] = (gogo){st,0};
			i = 0, j = 1;
			used[st] = 1;
			while(i < j) {
				int x = q[i].num;
				if(x == ed)	break;
				for(k=0;k<n;k++)
					if(used[k] == 0 && map[x][k]) {
						used[k] = 1;
						q[j++] = (gogo){k,q[i].cnt+1};
					}
				i++;
			}
			printf("%s %s %d\n",start,end,q[i].cnt);
		}
	}
	
	return 0;
}
