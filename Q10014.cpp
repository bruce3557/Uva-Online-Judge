#include <stdio.h>
double c[3010],a0,an1,sum;
int main(){
	int t,n,tc=0;
	int i;
	scanf("%d",&t);
	while(t--){
		if(tc)	puts("");
		else	tc = 1;
		scanf("%d",&n);
		scanf("%lf%lf",&a0,&an1);
		sum = 0.0000;
		for(i=1;i<=n;i++)
			scanf("%lf",c+i);
		for(i=n;i>0;i--)
			sum += (n-i+1)*2*c[i];
		printf("%.2lf\n",(n*a0+an1-sum)/(n+1));
	}
	return 0;
}
