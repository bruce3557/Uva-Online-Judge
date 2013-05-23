#include <stdio.h>

int n,s[1010];

int main() {
	int t;
	int sum,i,j,count;
	double aver;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		sum = 0;
		for(i=0;i<n;i++) {
			scanf("%d",s+i);
			sum += s[i];
		}
		aver = (double)sum/n;
		count = 0;
		for(i=0;i<n;i++)
			if(s[i] > aver)
				count++;
		
		printf("%.3lf%%\n",(double)count*100/n);
	}
	
	return 0;
}
