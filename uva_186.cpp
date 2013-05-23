#include <stdio.h>
#include <string.h>
#include <algorithm>

int len, num;
int length[110];
int pi[110];
char city[110][30];
char s[300];
char first[30], second[30];
bool used[110];

int dist[110];
int st[110];

struct node {
	int u, v;
	char name[30];
	int len;
	bool operator < (const node &t) const {
		return (u < t.u || (u == t.u && v < t.v));
	}
} road[11010];

inline int Find(int pre,int now) {
	s[now] = '\0';
	for(int i=0;i<len;++i)
		if( !strcmp(s+pre, city[i]) )
			return i;
	for(int i=pre;i<now;++i)
		city[len][i-pre] = s[i];
	city[len][now-pre] = '\0';
	return len++;
}

inline int find_edge(int u, int v, int len) {
	for(int i=0;i<num;++i)
		if(road[i].len == len && ((road[i].u == u && road[i].v == v) || (road[i].u == v && road[i].v == u)))
			return i;
}

int main() {
	int c=0;
	num = 0;
	while(gets(s) && strcmp(s,"")) {
		int i,pre=0;
		for(i=0;s[i] != '\0';++i)
			if(s[i] == ',')
				break;
				
		int p1 = Find(pre, i);
		++i; pre = i;
		for(;s[i] != '\0';++i)
			if(s[i] == ',')
				break;
				
		int p2 = Find(pre, i);
		char name[30];
		++i; pre = i;
		for(;s[i] != '\0';++i) {
			if(s[i] == ',') { name[i-pre] = '\0'; break; }
			else			name[i-pre] = s[i];
		}
		int sum=0;
		++i; pre = i;
		for(;s[i] != '\0';++i) {
			if(s[i] < '0' || s[i] > '9')	break;
			else
				sum = sum*10+(s[i]-'0');
		}
		
		road[num].u = p1;
		road[num].v = p2;
		for(i=0;name[i] != '\0';++i)
			road[num].name[i] = name[i];
		road[num].len = sum;
		++num;
		road[num].u = p2;
		road[num].v = p1;
		for(i=0;name[i] != '\0';++i)
			road[num].name[i] = name[i];
		road[num].len = sum;
		++num;
	}
	
	std::sort(road, road+num);
	for(int i=0;i<len;++i)
		st[i] = -1;
	for(int i=0;i<num;++i)
		if(st[road[i].u] == -1)
			st[road[i].u] = i;
	st[len] = num;
	for(int i=len-1;i>=0;--i)
		if(st[i] == -1)
			st[i] = st[i+1];
			
	while(gets(s) != NULL) {
		int i, pre=0;
		for(i=0;s[i] != '\0';++i) {
			if(s[i] == ',') { s[i] = '\0'; break; }
			else	first[i] = s[i];
		}
		int p1 = Find(pre, i);
		++i; pre=i;	
		for(;;++i) {
			if(s[i] == ',' || s[i] == '\0') { second[i-pre] = '\0'; break; }
			else	second[i-pre] = s[i];
		}
		int p2 = Find(pre, i);
		
		memset(used, 0, sizeof(used));
		for(int i=0;i<len;++i) {
			dist[i] = 999999999;
			pi[i] = -1;
		}
		
		dist[p1] = 0;
		for(int i=0;i<len;++i) {
			int ptr=-1;
			for(int j=0;j<len;++j)
				if(!used[j] && (ptr == -1 || (dist[ptr] > dist[j])))
					ptr = j;
			if(ptr == -1 || used[ptr])	break;
			used[ptr] = 1;
			for(int j=st[ptr];j<st[ptr+1];++j)
				if(!used[road[j].v] && (dist[road[j].v] > dist[ptr]+road[j].len)) {
					dist[road[j].v] = dist[ptr]+road[j].len;
					pi[road[j].v] = ptr;
				}
		}
		
		int ans_len=0;
		int ans[110];
		for(int ptr=p2;ptr != -1;ptr = pi[ptr])
			ans[ans_len++] = ptr;
		
		puts("\n");
		printf("From                 To                   Route      Miles\n");
		printf("-------------------- -------------------- ---------- -----\n");
		for(int i=ans_len-1;i>0;--i) {
			int ptr = find_edge(ans[i], ans[i-1], dist[ans[i-1]]-dist[ans[i]]);
			printf("%-20s %-20s %-10s %5d\n",city[ans[i]],city[ans[i-1]],road[ptr].name,road[ptr].len);
		}
		printf("                                                     -----\n");
		printf("                                          Total      %5d\n",dist[p2]);
	}

	return 0;
}
