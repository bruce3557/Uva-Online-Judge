#include <stdio.h>

int main(){
	int t,i,j,n,c=0,l,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&l);
		for(i=0;i<l;i++){
			if(c)	puts("");
			else	c = 1;
			for(j=1;j<=n;j++,puts(""))
				for(k=0;k<j;k++)
					printf("%d",j);
			for(j=n-1;j>0;j--,puts(""))
				for(k=0;k<j;k++)
					printf("%d",j);
		}
	}
	return 0;
}
