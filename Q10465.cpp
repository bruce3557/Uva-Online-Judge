#include <stdio.h>
#include <string.h>

int s[10010],n,m,t;

int Max(int a,int b) {
	return a>b?a:b;
}

int main() {
	int i,j;
	
	while(scanf("%d%d%d",&n,&m,&t) != EOF) {
		memset(s,0,sizeof(s));
		for(i=0;i*n<=t;i++) {
			for(j=0;j*m<=t-i*n;j++)
				s[i*n+j*m] = Max(s[i*n+j*m],i+j);
		}
		
		if(s[t] == 0) {
			for(i=t;i>0 && s[i] == 0;i--);
			printf("%d %d\n",s[i],t-i);
		} else {
			printf("%d\n",s[t]);
		}
	}

	return 0;
}
