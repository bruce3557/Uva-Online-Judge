#include <stdio.h>
int n;
int abs(int x){
	if(x<0)	return -x;
	return x;
}
int main(){
	int t,i,j,ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans = (n * 63 + 7492)*5-498;
		printf("%d\n",abs(ans)/10%10);
	}
	return 0;
}
