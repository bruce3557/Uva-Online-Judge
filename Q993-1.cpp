#include <stdio.h>
#include <string.h>
#include <algorithm>

int n,s[200],len;

int main() {
	int t,i,j;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		if(n == 0) {
			puts("0");
			continue;
		}
		if(n == 1) {
			puts("1");
			continue;
		}
		
		len = 0;
		int tmp = n;
		while(tmp > 1) {
			if(tmp % 2)	break;
			tmp /= 2;
			s[len++] = 2;
		}
		
		while(tmp > 1) {
			if(tmp % 3)	break;
			tmp /= 3;
			s[len++] = 3;
		}
		
		while(tmp > 1) {
			if(tmp % 5)	break;
			tmp /= 5;
			s[len++] = 5;
		}
		
		while(tmp > 1) {
			if(tmp % 7)	break;
			tmp /= 7;
			s[len++] = 7;
		}
		
		if(tmp > 1) {
			puts("-1");
			continue;
		}
		
		/*for(i=0;i<len;i++)
			printf("%d ",s[i]);
		puts("");*/
		while(1) {
			for(i=len-1;i>=0;i--) {
				for(j=i-1;j>=0;j--)
					if(s[i]*s[j] < 10)
						break;
				if(j >= 0) break;
			}
			if(i < 0)	break;
			s[j] = s[i]*s[j];
			for(j=i;j<len;j++)
				s[j] = s[j+1];
			len--;
			std::sort(s,s+len);
		}
		
		std::sort(s,s+len);
		for(i=0;i<len;i++)
			printf("%d",s[i]);
		puts("");
	}
	
	return 0;
}
