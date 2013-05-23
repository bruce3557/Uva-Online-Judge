#include <stdio.h>
#include <algorithm>

int s[110],t[110],n,ans[300],cnt;

void rev(int k) {
	int i,tmp[110];
	for(i=0;i<=k;i++)
		tmp[i] = s[k-i];
	for(i=0;i<=k;i++)
		s[i] = tmp[i];
}

void flip(int k) {
	int i,tmp[110];
	if(s[0] == t[k]) {
		ans[cnt++] = n-k;
		rev(k);
	} else {
		for(i=0;i<n && s[i] != t[k];i++);
		ans[cnt++] = n-i;
		rev(i);
		ans[cnt++] = n-k;
		rev(k);
	}
}

int main() {
	int i,j,k;
	char c;
	
	while(scanf("%d%c ",&s[0],&c) != EOF) {
		n=1;
		while(c != '\n')
			scanf("%d%c",&s[n++],&c);
		for(i=0;i<n;i++)
			t[i] = s[i];
		std::sort(t,t+n);
		cnt = 0;
		for(i=0;i<n-1;i++)
			printf("%d ",s[i]);
		printf("%d\n",s[i]);
		
		for(k=n-1;k>0;k--)
			if(s[k] != t[k])
				flip(k);
		
		for(i=0;i<cnt;i++)
			printf("%d ",ans[i]);
		puts("0");
	}
	
	return 0;
}
