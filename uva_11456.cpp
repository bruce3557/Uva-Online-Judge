#include <stdio.h>
int s[4010],n,lis[4010];
int main(){
	int t,i,j,max;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=n;i<2*n;i++)
			scanf("%d",&s[i]);
		for(i=0;i<2*n;i++)
			lis[i] = 1;
		for(i=n;i<2*n;i++)
			s[2*n-i-1] = s[i];
		max = 0;
		for(i=0;i<2*n;i++)
			for(j=0;j<i;j++)
				if( s[j] > s[i] && lis[j]+1>lis[i] )
					lis[i] = lis[j]+1;
		for(i=0;i<2*n;i++)
			if( max < lis[i] )
				max = lis[i];
		printf("%d\n",max);
	}
	return 0;
}
