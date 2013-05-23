#include <stdio.h>
#include <string.h>

int n,deg[1000];
char s[1000][5];

int main() {

	int t,i,j;
	char flag,c;
	
	scanf("%d",&t);
	while(t--) {
		n = 0;
		memset(deg,0,sizeof(deg));
		while(scanf("%s%c",&s[n],&c) && c != '\n')	n++;
		n++;
		for(i=0;i<n;i++)
			for(j=0;j<i;j++)
				if(i != j) {
					if(s[i][0] == 'F') {
						if(s[j][0] == 'M') {
							deg[i]++,deg[j]++;
							if(s[i][1] == 'M') {
								if(s[j][1] == 'F')
									deg[i]++,deg[j]++;
							} else {
								if(s[j][1] == 'M')
									deg[i]++,deg[j]++;
							}
						} else if(s[j][1] == 'M') {
							deg[i]++,deg[j]++;
							if(s[i][1] == 'M') {
								if(s[j][0] == 'F')
									deg[i]++,deg[j]++;
							} else {
								if(s[j][0] == 'M')
									deg[i]++,deg[j]++;
							}
						}
					} else {
						if(s[j][0] == 'F') {
							deg[i]++,deg[j]++;
							if(s[i][1] == 'F') {
								if(s[j][1] == 'M')
									deg[i]++,deg[j]++;
							} else {
								if(s[j][1] == 'F')
									deg[i]++,deg[j]++;
							}
						} else if(s[j][1] == 'F') {
							deg[i]++,deg[j]++;
							if(s[i][1] == 'F') {
								if(s[j][0] == 'M')
									deg[i]++,deg[j]++;
							} else {
								if(s[j][0] == 'F')
									deg[i]++,deg[j]++;
							}
						}
					}
				}
		
		flag = 0;
		for(i=0;i<n;i++)
			if(deg[i] == 0 || (deg[i]&1)) {
				flag = 1;
				break;
			}
		if(flag) {
			puts("NO LOOP");
		} else {
			puts("LOOP");
		}
	}
	
	return 0;
}
