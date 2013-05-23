#include <stdio.h>
#include <string.h>

char baudot[2][50],goal[100],ans[100];

int main() {
	
	int i,n,tmp,sum,j,k,len;
	
	gets(baudot[0]);
	gets(baudot[1]);
	
	while(gets(goal) != NULL) {
		n = strlen(goal);
		for(i=0;i<n;i++)
			goal[i] -= '0';
		k = len = 0;
		for(i=0;i<n;i+=5) {
			tmp = 1, sum = 0;
			for(j=i+4;j>=i;j--,tmp*=2) 
				sum += tmp*goal[j];
			if(sum == 31) {
				k = 1;
			} else if(sum == 27) {
				k = 0;
			} else {
				ans[len++] = baudot[k][sum];
			}
		}
		ans[len] = '\0';
		
		puts(ans);
	}
	
	return 0;
}
