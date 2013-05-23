#include <stdio.h>
#include <string.h>
#include <math.h>
#define exp (1e-11)

struct node {
	char s[30];
	double num;
} p[100],tmp[200];

int n,m;

int main() {
	int i,j,c,cnt,tt;
	double sum;
	
	while(scanf("%d%d",&n,&m) != EOF) {
		for(i=0;i<n;i++) {
			scanf("%s%lf",p[i].s,&p[i].num);
			p[i].num *= 10;
		}
		c=0;
		while(m--) {
			cnt = 0;
			while(scanf("%s",tmp[cnt].s)) {
				if(strcmp(tmp[cnt].s,"=") == 0 || strcmp(tmp[cnt].s,"<") == 0 || strcmp(tmp[cnt].s,"<=") == 0 || strcmp(tmp[cnt].s,">") == 0 || strcmp(tmp[cnt].s,">=") == 0)
					break;
				cnt++;
			}
			scanf("%d",&tt);
			tt*=10;
			
			sum = 0.0;
			for(i=0;i<cnt;i++) {
				if(strcmp(tmp[i].s,"+") == 0)	continue;
				for(j=0;j<n;j++)
					if(strcmp(tmp[i].s,p[j].s) == 0)
						break;
				sum += p[j].num;
			}
			
			int a = sum;
			if(strcmp(tmp[cnt].s,"=") == 0 && a == tt)
				printf("Guess #%d was correct.\n",++c);
			else if(strcmp(tmp[cnt].s,"<") == 0 && a < tt)
				printf("Guess #%d was correct.\n",++c);
			else if(strcmp(tmp[cnt].s,"<=") == 0 && a <= tt)
				printf("Guess #%d was correct.\n",++c);
			else if(strcmp(tmp[cnt].s,">") == 0 && a > tt)
				printf("Guess #%d was correct.\n",++c);
			else if(strcmp(tmp[cnt].s,">=") == 0 && a >= tt)
				printf("Guess #%d was correct.\n",++c);
			else
				printf("Guess #%d was incorrect.\n",++c);
		}
	}
	
	return 0;
}
