#include <stdio.h>
#include <math.h>
int main(){
	int t,i,j,k,A,B,C,a,b,c;
	char flag;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&A,&B,&C);
		flag = 0;
		for(i = -(int)sqrt(C);i*i <= C;i++)
			if(i && B % i == 0){
				for(j = -(int)sqrt(C);j*j <= C;j++)
					if(i != j && j && (B/i) % j == 0){
						k = A-i-j;
						if(i != k && j != k && k*k == C-i*i-j*j && k == B/i/j){
							flag = 1;
							break;
						}
					}
				if(flag)	break;
			}
		if(flag)
			printf("%d %d %d\n",i,j,k);
		else
			puts("No solution.");
	}
	return 0;
}
