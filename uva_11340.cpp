#include <stdio.h>
#include <string.h>

int n;
int D[500];
char s[100010];

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		gets(s);
		memset(D, 0 ,sizeof(D));
		for(int i=0;i<n;++i) {
			gets(s);
			char x;
			int w;
			sscanf(s,"%c %d", &x, &w);
			D[x+128] = w;
		}
		
		double sum = 0.0;
		int m;
		scanf("%d",&m);
		gets(s);
		for(int i=0;i<m;++i) {
			gets(s);
			int len = strlen(s);
			for(int j=0;j<len;++j)
				sum += D[s[j]+128];
		}
		printf("%.2lf$\n",sum/100);
	}
	
	return 0;
}
