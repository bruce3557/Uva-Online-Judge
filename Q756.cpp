#include <stdio.h>

//23->physical 28->emotion 33->intellegence

int main() {
	int a,b,c,d,t=0,ans,e;
	
	while(scanf("%d%d%d%d",&a,&b,&c,&d)) {
		if(a == -1 && b == a && c == b && d == c)	break;
		
		b -= a;
		c -= a;
		e = a;
		while(1) {
			if(b % 28 == 0)	break;
			b -= 23;
			c -= 23;
			e += 23;
		}
		while(1) {
			if(c % 33 == 0)	break;
			c -= 23*28;
			e += 23*28;
		}
		ans = e-d;
		if(ans > 21252)
			ans -= 21252;
		else if(ans <= 0)
			ans += 21252;
		printf("Case %d: the next triple peak occurs in %d days.\n",++t,ans);
	}
	
	return 0;
}
