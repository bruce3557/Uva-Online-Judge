#include <stdio.h>

long long humble[6000],n,len;

int main(){
	long long min,a,b,c,d,i;
	len = 0;
	humble[len++] = 1;
	while(len < 5842){
		min = 2147483647;
		for(i=0;i<len;i++){
			a = 2*humble[i];
			b = 3*humble[i];
			c = 5*humble[i];
			d = 7*humble[i];
			if(a > humble[len-1] && min > a)
				min = a;
			else if(b > humble[len-1] && min > b)
				min = b;
			else if(c > humble[len-1] && min > c)
				min = c;
			else if(d > humble[len-1] && min > d)
				min = d;
		}
		humble[len++] = min;
	}
	
	while(scanf("%lld",&n) && n){
		if(n%100 > 10 && n%100 < 20){
			printf("The %lldth humble number is %lld.\n",n,humble[n-1]);
		} else if(n % 10 == 1){
			printf("The %lldst humble number is %lld.\n",n,humble[n-1]);
		} else if(n % 10 == 2){
			printf("The %lldnd humble number is %lld.\n",n,humble[n-1]);
		} else if(n % 10 == 3){
			printf("The %lldrd humble number is %lld.\n",n,humble[n-1]);
		} else {
			printf("The %lldth humble number is %lld.\n",n,humble[n-1]);
		}
	}
	return 0;
}
