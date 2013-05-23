#include <stdio.h>
#include <algorithm>

int main() {
	
	long long t,c=0,s[5];
	
	scanf("%lld",&t);
	
	while(t--) {
		scanf("%lld%lld%lld",s,s+1,s+2);
		
		std::sort(s,s+3);
		
		printf("Case %lld: ",++c);
		if(s[0] <= 0 || s[0]+s[1] <= s[2] || s[2]-s[1] >= s[0]) {
			puts("Invalid");
			continue;
		}
		if(s[0] == s[1] && s[1] == s[2]) {
			puts("Equilateral");
			continue;
		}
		if(s[0] == s[1] || s[1] == s[2]) {
			puts("Isosceles");
			continue;
		}
		puts("Scalene");
	}
	
	return 0;
}
