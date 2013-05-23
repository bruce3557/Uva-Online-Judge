#include <stdio.h>
#include <string.h>
#include <set>
using std::set;

int n;
int s[110];

int main() {
	int c=0;
	
	while(scanf("%d",&n) != EOF) {
		//if(c)	puts("");
		//printf("%d\n",n);
		for(int i=0;i<n;i++)
			scanf("%d",s+i);
		bool yes = false;
		if(s[0] < 1) {
			yes = true;
			//puts("VVV");
		}
		for(int i=1;i<n;i++)
			if(s[i] <= s[i-1]) {
				yes =true;
				//puts("VVV");
				break;
			}
			
		set< int > saver;
		for(int i=0;i<n;i++) {
			for(int j=0;j<=i;j++) {
				//printf("%d + %d : %d\n",i,j,s[i]+s[j]);
				if( saver.find(s[i]+s[j]) != saver.end() ) {
					yes = true;
					break;
				}
				saver.insert(s[i]+s[j]);
			}
			if(yes)	break;
		}
		
		printf("Case #%d: ",++c);
		if(!yes)
			puts("It is a B2-Sequence.\n");
		else
			puts("It is not a B2-Sequence.\n");
	}

	return 0;
}
