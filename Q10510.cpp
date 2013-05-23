#include <stdio.h>
#include <string.h>
#include <algorithm>

struct node {
	int a,b;
	bool operator < (node t) const {
		return a < t.a;
	}
} edge[10010];

struct sta {
	int top;
	int stack[10010];
	
	sta() { top = 0; }
	
	bool find(int x) {
		for(int i=0;i<top;i++)
			if(x == stack[i])
				return true;
		return false;
	}
	
	void push(int x) {
		stack[top++] = x;
	}
	
	int pop() {
		return stack[--top];
	}
}stk;

int min(int a,int b) {
	return a < b ? a : b;
}

int n,m,count,st[10010],cnt;
int lowlink[10010],d[10010],f[10010],num[10010],ind[10010],outd[10010];

void go(int now) {
	if(cnt) return;
	d[now] = count;
	lowlink[now] = count;
	count++;
	stk.push(now);
	int i,x;
	for(i=st[now];i<st[now+1];i++) {
		x = edge[i].b;
		if(d[x] == -1) {
			go(x);
			if(cnt)	return;
			lowlink[now] = min(lowlink[now],lowlink[x]);
		} else if(stk.find(x) == true) {
			lowlink[now] = min(lowlink[now],d[x]);
			if(f[x] == -1)
				num[now]++;  //back edge
			else {
				cnt = 1;	//C edge or forward edge
				return;
			}
		}
	}
	f[now] = count++;
	if(lowlink[now] == d[now]) {
		do {
			x = stk.pop();
		} while(x != now);
	}
}

int main() {
	int t,i,j,k;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		memset(num,0,sizeof(int)*n);
		memset(ind,0,sizeof(int)*n);
		memset(outd,0,sizeof(int)*n);
		if(n == 1 && m == 0) {
			puts("YES");
			continue;
		}
		stk.top = 0;
		for(i=0;i<m;i++) {
			scanf("%d%d",&edge[i].a,&edge[i].b);
			ind[edge[i].b]++;
			outd[edge[i].a]++;
		}
		std::sort(edge,edge+m);
		
		for(i=0;i<n;i++)
			st[i] = d[i] = f[i] = -1;
		count = cnt = 0;
		for(i=0;i<m;i++)
			if(st[edge[i].a] == -1)
				st[edge[i].a] = i;
		st[n] = m;
		for(i=0;i<n && ind[i] == outd[i];i++);
		if(i < n) {
			puts("NO");
			continue;
		}
		go(0);
		if(cnt == 0) {
			for(i=0;i<n && d[i] != -1;i++);
			if(i < n) cnt = 1;
			for(i=0;i<n && num[i] <= 1;i++);
			if(i < n) cnt = 1;
			if(cnt == 0) {
				puts("YES");
				continue;
			}
		}
		
		puts("NO");
	}
	
	return 0;
}
