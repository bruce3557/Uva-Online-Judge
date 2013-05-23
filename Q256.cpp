#include <stdio.h>

int main() {
	int n,i,j,k;
	
	while(scanf("%d",&n) != EOF) {
		j = 1;
		for(i=0;i<n/2;i++)
			j *= 10;
		for(i=0;i<j;i++)
			for(k=0;k<j;k++)
				if((i+k)*(i+k) == (i*j)+k) {
					if(n == 2)
						printf("%d%d\n",i,k);
					else if(n == 4)
						printf("%02d%02d\n",i,k);
					else if(n == 6)
						printf("%03d%03d\n",i,k);
					else
						printf("%04d%04d\n",i,k);
				}
	}
	
	return 0;
}
