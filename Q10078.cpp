#include <stdio.h>
#include <string.h>

int n;
struct node {
	int x,y;
} s[110];

bool Input() {
	scanf("%d",&n);
	if(!n)	return false;
	for(int i=0;i<n;i++)
		scanf("%d%d",&s[i].x,&s[i].y);
	return true;
}

bool Solve() {
	int pos;
	pos = s[0].x*(s[1].y-s[2].y)+s[1].x*(s[2].y-s[0].y)+s[2].x*(s[0].y-s[1].y);
	for(int i=1;i<n;i++) {
		int j,k;
		j = (i+1)%n;
		k = (j+1)%n;
		int tmp = s[i].x*(s[j].y-s[k].y)+s[j].x*(s[k].y-s[i].y)+s[k].x*(s[i].y-s[j].y);
		if( (tmp < 0 && pos > 0) || (tmp > 0 && pos < 0) )	return true;
	}
	return false;
}

int main() {
	
	while( Input() ) {
		bool ans = Solve();
		if(ans)	puts("Yes");
		else	puts("No");
	}
	
	return 0;
}
