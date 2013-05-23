#include <stdio.h>
#include <string.h>

int n;
int s[1010];

int Calc(int num) {
	int count = 0;
	int p = n-1,pre = n-1;
	while(1) {
		if(num == 0 || p < 0)	return count;
		for(;p>=0 && s[p] > num;p--);
		num -= s[p];
		if(p == pre)	continue;
		pre = p;
		count++;
	}
}

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",s+i);
		printf("%d\n",Calc(s[n-1]-1)+1);
	}
	
	return 0;
}
