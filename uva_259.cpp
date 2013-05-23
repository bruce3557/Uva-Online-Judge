#include <stdio.h>
#include <string.h>

int n = 26;
char name[26];
char s[1010];
int total;
int map[50][50];

inline bool read() {
	bool suc = true;
	total = 0;
	memset(map, 0, sizeof(map));
	while( 1 ) {
		if( gets(s) == NULL ) {
			suc = false;
			break;
		}
		if( !strcmp("", s) )	break;
		char fe[10], ov[20];
		//puts(s);
		sscanf(s,"%s %s",fe,ov);
		//puts(fe);
		//puts(ov);
		int id = fe[0]-'A'+1;
		int cp = fe[1]-'0';
		int len = strlen(ov);
		--len;
		total += cp;
		map[0][id] += cp;
		//printf("%d:\n",id);
		for(int i=0;i<len;++i) {
			int x = ov[i]-'0'+27;
			map[id][x] = 1;
			//printf("%d\n",x);
		}
	}
	if( !suc )	return false;
	
	for(int i=0;i<10;++i)
		map[i+27][37] = 1;
	
	return true;
}

int min;
int pre[50];

int find_path(int now,int ed){
    if(now == ed)	return 1;
    for(int i = 1;i <= 37; i++)
	   if(pre[i] == -1 && map[now][i] > 0){
		    int temp = min;
	       if( min > map[now][i] )
			min = map[now][i];
	       pre[i] = now;
	       if( find_path(i,ed) == 1 ){
				map[now][i] -= min;	map[i][now] += min;
				return 1;
	       }
		   min = temp;
		   pre[i] = -1;
		}
    return 0;
}

int Maxflow(int st, int ed) {
	int i,sum = 0;
	while(1){
		for(i=1;i<=37;i++)    pre[i] = -1;
		min = 999999999;
		pre[st] = 0;
		if( find_path(st,ed) == 0 )	return sum;
		sum += min;
	}
}

inline void Solve() {
	//puts("OAO");
	int sum = Maxflow(0, 37);
	//printf("%d %d\n",sum, total);
	if(sum != total)	puts("!");
	else {
		for(int i=0;i<10;++i) {
			bool find = false;
			for(int j=1;j<=26;++j)
				if(map[i+27][j]) {
					find = true;
					printf("%c",j+'A'-1);
					break;
				}
			if( !find )	printf("_");
		}
		puts("");
	}
}

int main() {
	while(1) {
		bool suc = read();
		Solve();
		if( !suc )	break;
	}
	return 0;
}
