#include <stdio.h>
#include <string.h>
#include <algorithm>

struct node {
	int a,b,len;
	
	bool operator < (node t) const {
		return len < t.len;
	}
} e[500];

int n,m,u[110],T[110];

int find(int now) {
	if(u[now] == now)	return now;
	return u[now] = find(u[now]);
}

int main() {
	int i,j,k,t,a,b,count,c=0;
	int first,second,sum;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		m*=2;
		for(i=1;i<=n;i++)
			u[i] = i;
		for(i=0;i<m;i+=2) {	
			scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].len);
			e[i+1] = (node){e[i].b,e[i].a,e[i].len};
		}
		std::sort(e,e+m);
		first = 0;
		second = 999999999;
		
		k = i = 0;
		while(i < m && k < n-1) {
			a = find(e[i].a);
			b = find(e[i].b);
			if(a == b) {
				i++;
				continue;
			}
			u[a] = b;
			first += e[i].len;
			T[k] = i;
			i++,k++;
		}
		
		printf("Case #%d : ",++c);
		count = find(u[1]);
		for(i=2;i<=n && find(u[i]) == count;i++);
		if(i <= n) {
			puts("No way");
			continue;
		}
		
		for(j=0;j<n-1;j++) {
			for(i=1;i<=n;i++)
				u[i] = i;
			k = i = sum = 0;
			while(i < m && k < n-1) {
				if(i == T[j] || (e[i].a == e[T[j]].b && e[i].b == e[T[j]].a && e[i].len == e[T[j]].len)) {
					i++;
					continue;
				}
				a = find(e[i].a);
				b = find(e[i].b);
				if(a == b) {
					i++;
					continue;
				}
				u[a] = b;
				sum += e[i].len;
				i++,k++;
			}
			count = find(u[1]);
			for(i=2;i<=n && find(u[i]) == count;i++);
			if(i > n && second > sum)	second = sum;
		}
		
		if(second >= 999999999) {
			puts("No second way");
			continue;
		}
		
		printf("%d\n",second);
	}
	
	return 0;
}
