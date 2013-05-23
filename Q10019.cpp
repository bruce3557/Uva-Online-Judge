#include <stdio.h>

int main() {
	int n,t1,t2,tmp,t,i;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		t1 = t2 = 0;
		tmp = n;
		while(tmp > 0) {
			if(tmp % 2)	t1++;
			tmp /= 2;
		}
		
		tmp = n;
		while(tmp > 0) {
			i = tmp%10;
			while(i > 0) {
				if(i % 2)	t2++;
				i /= 2;
			}
			tmp /= 10;
		}
		printf("%d %d\n",t1,t2);
	}
	
	return 0;
}
