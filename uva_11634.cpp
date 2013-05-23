#include <stdio.h>
#include <string.h>

int num,count,s[10];
char used[10010];

int main() {
	int i,tmp;
	
	while(scanf("%d",&num) && num) {
		memset(used,0,sizeof(used));
		tmp = num;
		
		used[tmp] = 1;
		while(1) {
			tmp = tmp*tmp;
			for(i=0;tmp>0;i++) {
				s[i] = tmp%10;
				tmp /= 10;
			}
			for(;i<8;i++)
				s[i] = 0;
			tmp = 0;
			for(i=5;i>=2;i--)
				tmp = tmp*10+s[i];
			if(used[tmp])	break;
			used[tmp] = 1;
		}
		
		count = 0;
		for(i=0;i<10000;i++)
			if(used[i])
				count++;
		printf("%d\n",count);
	}
	
	return 0;
}
