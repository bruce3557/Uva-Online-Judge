#include <stdio.h>
#include <string.h>
#include <algorithm>

int n,m,st[1010],str[1010],d[1010],f[1010],Time;
struct node {
	char name[25];
	
	void getName() {
		gets(name);
	}
	
	bool operator < (const node &t) const {
		return (strcmp(name,t.name) <= 0);
	}
} peo[1010];

struct Node {
	int a,b;
	
	bool operator < (const Node &t) const {
		return a < t.a;
	}
} e[1000010],er[1000010],fin[1010];

int getIndex(char *s) {
	int st,ed,mid;
	
	st = 0, ed = n;
	while(st < ed) {
		mid = (st+ed)/2;
		int tmp = strcmp(s,peo[mid].name);
		if(tmp == 0)	return mid;
		else if(tmp < 0) ed = mid;
		else	st = mid+1;
	}
	
	return -1;
}

bool Input() {
	scanf("%d%d%*c",&n,&m);
	if(n == 0 && m == 0)	return false;
	for(int i=0;i<n;i++)
		peo[i].getName();
	std::sort(peo,peo+n);
	
	for(int i=0;i<m;i++) {
		char s[25],t[25];
		gets(s);
		int j = getIndex(s);
		gets(t);
		int k = getIndex(t);
		e[i] = (Node){j,k};
		er[i] = (Node){k,j};
	}
	std::sort(e,e+m);
	std::sort(er,er+m);
	for(int i=0;i<n;i++)
		st[i] = str[i] = -1;
	for(int i=0;i<m;i++) {
		if(st[e[i].a] == -1)
			st[e[i].a] = i;
		if(str[er[i].a] == -1)
			str[er[i].a] = i;
	}
	st[n] = str[n] = m;
	for(int i=n-1;i>=0;i--) {
		if(st[i] == -1)
			st[i] = st[i+1];
		if(str[i] == -1)
			str[i] = str[i+1];
	}
	
	return true;
}

void go(int now) {
	Time++;
	d[now] = Time;
	for(int i=st[now];i<st[now+1];i++)
		if(d[e[i].b] == 0)
			go(e[i].b);
	Time++;
	f[now] = Time;
}

void gogo(int now) {
	d[now] = 1;
	for(int i=str[now];i<str[now+1];i++)
		if(d[er[i].b] == 0)
			gogo(er[i].b);
}

int Solve() {
	int count = 0;
	Time = 0;
	memset(d,0,sizeof(d));
	memset(f,0,sizeof(f));
	
	for(int i=0;i<n;i++)
		if(d[i] == 0)
			go(i);
	
	for(int i=0;i<n;i++)
		fin[i] = (Node){f[i],i};
	std::sort(fin,fin+n);
	
	memset(d,0,sizeof(d));
	for(int i=n-1;i>=0;i--)
		if(d[fin[i].b] == 0) {
			count++;
			gogo(fin[i].b);
		}
	
	return count;
}

int main() {

	while( Input() ) 
		printf("%d\n",Solve());

	return 0;
}
