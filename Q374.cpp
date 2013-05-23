#include <stdio.h>
int BigMod(int b,int p,int m){
	if(p == 0)	return 1;
	int a = BigMod(b%m,p/2,m)%m,i;
	if(p % 2)	return (((a*a)%m)*(b%m))%m;
	return (a*a)%m;
}
int main(){
	int n,m,p;
	while(scanf("%d%d%d",&n,&p,&m)!=EOF)
		printf("%d\n",BigMod(n%m,p,m));
	return 0;
}
