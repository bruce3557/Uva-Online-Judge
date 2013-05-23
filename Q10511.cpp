#include <stdio.h>
#include <string.h>
#include <algorithm>
#define con (1000)

int n,m,k,num,st[4210];
int map[4210][4210];
char name[1010][100],party[1010][100],club[1010][100];

struct node {
	int a,b;
	bool operator < (node t) const {
		return a < t.a;
	}
} e[2000010];

int MaxFlow(int stk,int ed) {
	int i,j,g,t,pre[4210],sum=0,q[4210];
	
	while(1) {
		for(i=stk;i<=ed;i++)
			pre[i] = -1;
		q[0] = stk, i = 0, j = 1, pre[stk] = 0;
		while(i < j) {
			if(q[i] == ed)	break;
			t = q[i];
			for(g=st[t];g<st[t+1];g++)
				if(pre[e[g].b] == -1 && map[t][e[g].b] > 0) {
					pre[e[g].b] = t;
					q[j++] = e[g].b;
				}
			i++;
		}
		if(i >= j)	return sum;
		sum++;
		for(g=ed;g!=stk;g=pre[g]) {
			map[pre[g]][g]--;
			map[g][pre[g]]++;
		}
	}
}

int main() {
	int t,i,j,p,q,d,len,ttlen;
	char tt[200],gg[200],c;
	
	scanf("%d%*c",&t);
	gets(tt);
	while(t>0) {
		memset(map,0,sizeof(map));
		n = m = k = d = num = 0;
		while(1) {
			gets(gg);
			ttlen = strlen(gg);
			if(ttlen == 0)	break;
			len = 0;
			for(i=len;gg[i] != ' ';i++)
				name[n][i] = gg[i];
			name[n][i] = '\0';
			len = i;
			
			for(i=len+1,j=0;i < ttlen && gg[i] != ' ' && gg[i] != '\0';i++,j++)
				tt[j] = gg[i];
			tt[j] = '\0';
			len = i;
			for(i=0;i<m;i++)
				if(strcmp(party[i],tt) == 0)
					break;
			if(i >= m) {
				for(j=0;tt[j] != '\0';j++)
					party[m][j] = tt[j];
				party[m][j] = '\0';
				m++;
			}
			d = i;
			
			while(len < ttlen) {
				for(j=len+1,q=0;j < ttlen && gg[j] != ' ' && gg[j] != '\0';j++,q++)
					tt[q] = gg[j];
				tt[q] = '\0';
				len = j;
				for(i=0;i<k;i++)
					if(strcmp(club[i],tt) == 0)
						break;
				if(i >= k) {
					for(j=0;tt[j] != '\0';j++)
						 club[k][j] = tt[j];
					club[k][j] = '\0';
					map[k+con+con+1][k+con+con+con+1] = 1;
					e[num++] = (node){k+con+con+1,k+con+con+con+1};
					e[num++] = (node){k+con+con+con+1,k+con+con+1};
					k++;
				}
				if(map[d+con+1][i+con+con+1] == 0) {
					map[d+con+1][i+con+con+1] = 1;
					e[num++] = (node){d+con+1,i+con+con+1};
					e[num++] = (node){i+con+con+1,d+con+1};
				}
				map[i+con+con+con+1][n+1] = 1;
				e[num++] = (node){i+con+con+con+1,n+1};
				e[num++] = (node){n+1,i+con+con+con+1};
			}
			n++;
		}
		int sum = (k-1)/2;
		for(i=0;i<m;i++) {
			map[0][i+con+1] = sum;
			e[num++] = (node){0,i+con+1};
			e[num++] = (node){i+con+1,0};
		}
		for(i=0;i<n;i++) {
			map[i+1][4004] = 1;
			e[num++] = (node){i+1,4004};
			e[num++] = (node){4004,i+1};
		}
		std::sort(e,e+num);
		for(i=0;i<4005;i++)
			st[i] = -1;
		for(i=0;i<num;i++)
			if(st[e[i].a] == -1)
				st[e[i].a] = i;
		st[4005] = num;
		for(i=4004;i>=0;i--)
			if(st[i] == -1)
				st[i] = st[i+1];
		
		sum = MaxFlow(0,4004);
		
		if(sum != k) {
			puts("Impossible.");
			t--;
			if(t > 0)	puts("");
			continue;
		}
		
		for(i=0;i<n;i++)
			for(j=0;j<k;j++)
				if(map[i+1][j+con+con+con+1] > 0)
					printf("%s %s\n",name[i],club[j]);
		t--;
		if(t > 0)	puts("");
	}
	
	return 0;
}
