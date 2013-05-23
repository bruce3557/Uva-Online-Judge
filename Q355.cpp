#include <stdio.h>
#include <string.h>

int a,b,n,len;
char s[100],ans[100],digit[100];
long long sum,d;

int main() {

	int i,j;
	bool flag;
	
	while(scanf("%d%d%s",&a,&b,s) != EOF) {
		n = strlen(s);
		
		for(i=0;i<n;i++) {
			if(s[i] >= '0' && s[i]<='9')
				digit[n-i-1] = s[i]-'0';
			else if(s[i] >='A' && s[i] <='G')
				digit[n-i-1] = s[i]-'A'+10;
		}
		
		flag = 0;
		for(i=0;i<n;i++)
			if(digit[i] >= a) {
				flag = 1;
				break;
			}
		if(flag) {
			printf("%s is an illegal base %d number\n",s,a);
			continue;
		}
		sum = 0, d = 1,len = 0;
		for(i=0;i<n;i++,d*=(long long)a)
			sum += d*(long long)digit[i];
		if(sum == 0) {
			printf("0 base %d = 0 base %d\n",a,b);
			continue;
		}
		while(sum > 0) {
			ans[len++] = sum%(long long)b;
			sum /= (long long)b;
		}
		printf("%s base %d = ",s,a);
		for(i=len-1;i>=0;i--) {
			if(ans[i] >= 0 && ans[i] <= 9)
				printf("%c",ans[i]+'0');
			else if(ans[i] >= 10 && ans[i] <=15)
				printf("%c",ans[i]-10+'A');
		}
		printf(" base %d\n",b);
	}

	return 0;
}
