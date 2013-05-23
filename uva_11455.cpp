#include <stdio.h>
#include <algorithm>

int main() {

	long long t,s[6],i;

	scanf("%lld",&t);
	
	while(t--) {
	
		for(i=0;i<4;i++)
			scanf("%lld",s+i);
			
		std::sort(s,s+4);
		
		if(s[0] <= 0 || s[0]+s[1]+s[2] < s[3]) {
			puts("banana");
			continue;
		}
		if(s[0] == s[1] && s[1] == s[2] && s[2] == s[3]) {
			puts("square");
			continue;
		}
		if(s[0] == s[1] && s[2] == s[3]) {
			puts("rectangle");
			continue;
		}
		puts("quadrangle");
	}
		
	return 0;
}
