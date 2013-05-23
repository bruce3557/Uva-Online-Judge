#include <stdio.h>
#include <string.h>
#define eps (1e-8)

int n,m;
inline int pow2(int x,int y) {
	if(y == 0)	return 1;
	int tmp = pow2(x,y/2);
	if(y % 2) return tmp*tmp*x;
	else	return tmp*tmp;
}

int main() {
	
	while(scanf("%d%d",&n,&m) && n+m) {
		int k=1,ans;
		if(n == 1 && m == 1) {
			puts("0 1");
			continue;
		}
		
		while(1) {
			ans = 1;
			while(1) {
				if(pow2(ans,k) > m)	break;
				if(pow2(ans+1,k) == n && pow2(ans,k) == m)	break;
				ans++;
				if(ans > 1000)	break;
			}
			
			if(pow2(ans,k) == m)	break;			
			k++;
		}
		
		int sum1,sum2;
		sum2 = 0;
		if(ans == 1)	sum1 = k;
		else			sum1 = (int)(pow2(ans,k)-1)/(ans-1);
		int i=0;
		while(n > 0) {
			sum2 += n*pow2(ans,i);
			i++;
			n /= (ans+1);
		}
		
		printf("%d %d\n",sum1,sum2);
	}
	
	return 0;
}
