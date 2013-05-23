#include <stdio.h>
int s[60];
int main(){
	int t,i,j,tmp,count,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&s[i]);
		count = 0;
		for(i=0;i<n;i++)
			for(j=n-2;j>=0;j--)
				if(s[j]>s[j+1]){
					count++;
					tmp = s[j];
					s[j] = s[j+1];
					s[j+1] = tmp;
				}
		printf("Optimal train swapping takes %d swaps.\n",count);
	}
	return 0;
}
