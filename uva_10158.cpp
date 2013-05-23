#include <stdio.h>
#include <string.h>

int n;
int fri[10010];
int ene[10010];

inline int find(int now) {
	if(now == -1)	return -1;
	return (now == fri[now])?now:(fri[now]=find(fri[now]));
}

int main() {

	scanf("%d",&n);
	for(int i=0;i<n;++i) {
		fri[i] = i;
		ene[i] = -1;
	}
	int a,b,c;
	while(scanf("%d%d%d",&c,&a,&b) && a+b+c) {
		int fa=find(a);
		int fb=find(b);
		
		if(c == 1) {
			int efa=find(ene[fa]);
			int efb=find(ene[fb]);
			if(efa == fb || efb == fa) {
				puts("-1");
				continue;
			}
			if(ene[fa] != -1 && ene[fb] != -1)
				fri[find(ene[fa])] = find(ene[fb]);
			else if(ene[fa] != -1 && ene[fb] == -1)
				ene[fb] = find(ene[fa]);
			else if(ene[fb] != -1 && ene[fa] == -1)
				ene[fa] = find(ene[fb]);
			fri[fa] = fb;
		} else if(c == 2) {
			if(fa == fb) {
				puts("-1");
				continue;
			}
			if(ene[fa] == -1)	ene[fa] = fb;
			if(ene[fb] == -1)	ene[fb] = fa;
			fri[find(ene[fb])] = fa;
			fri[find(ene[fa])] = fb;
		} else if(c == 3) {
			(fa == fb)?puts("1"):puts("0");
		} else if(c == 4) {
			(find(ene[fa]) == fb)?puts("1"):puts("0");
		}
	}

	return 0;
}
