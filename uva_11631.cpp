#include <stdio.h>
#include <string.h>
#include <algorithm>

struct node {
	int a,b,len;
	
	bool operator < (node t) const {
		return len < t.len;
	}
} e[400010];

int n,m,u[200010];

int find(int now) {
	if(u[now] == now)	return now;
	return (u[now] = find(u[now]));
}

int main() {
	int i,j,k,sum,total;
	
	while(scanf("%d%d",&n,&m) && n+m) {
		for(i=0;i<n;i++)
			u[i] = i;
		m*=2;
		total = 0;
		for(i=0;i<m;i+=2) {
			scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].len);
			e[i+1] = (node){e[i].b,e[i].a,e[i].len};
			total += e[i].len;
		}
		
		std::sort(e,e+m);
		sum = k = i = 0;
		
		while(1) {
			if(k >= n-1)	break;
			int a,b;
			a = find(e[i].a);
			b = find(e[i].b);
			if(a == b) {
				i++;
				continue;
			}
			u[b] = a;
			sum += e[i].len;
			i++,k++;
		}
		
		printf("%d\n",total-sum);
	}
	
	return 0;
}
