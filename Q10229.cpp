#include <stdio.h>
int n,m,f[2000000];
int main(){
	int i,j,b,len;
	while(scanf("%d%d",&n,&m) != EOF){
		b = 1 << m;
		f[0] = 0, f[1] = 1 % b;
		len = 0;
		for(i=2;i<2000000;i++){
			f[i] = (f[i-1] + f[i-2])%b;
			if(f[i] == f[1] && f[i-1] == f[0])	break;
		}
		len = i-1;
		printf("%d\n",f[n%len]);
	}
	return 0;
}
