#include <stdio.h>

char s[20][20],t[20][20];
int n;

bool same() {
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(s[i][j] != t[i][j])
				return 0;
	return 1;
}

void rotate() {
	char tmp[20][20];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			tmp[j][n-i-1] = s[i][j];
			
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			s[i][j] = tmp[i][j];
	
}

void reflect() {
	char tmp[20][20];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			tmp[i][j] = s[n-i-1][j];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			s[i][j] = tmp[i][j];
}

int main() {

	int tt=0;
	int i;

	while(scanf("%d",&n) != EOF) {
	
		for(i=0;i<n;i++)
			scanf("%s%s",s[i],t[i]);
			
		if(same()) {
			printf("Pattern %d was preserved.\n",++tt);
			continue;
		}
		
		rotate();
		if(same()) {
			printf("Pattern %d was rotated 90 degrees.\n",++tt);
			continue;
		}
		
		rotate();
		if(same()) {
			printf("Pattern %d was rotated 180 degrees.\n",++tt);
			continue;
		}
		rotate();
		if(same()) {
			printf("Pattern %d was rotated 270 degrees.\n",++tt);
			continue;
		}
		
		rotate();
		reflect();
		if(same()) {
			printf("Pattern %d was reflected vertically.\n",++tt);
			continue;
		}
		
		rotate();
		if(same()) {
			printf("Pattern %d was reflected vertically and rotated 90 degrees.\n",++tt);
			continue;
		}
		
		rotate();
		if(same()) {
			printf("Pattern %d was reflected vertically and rotated 180 degrees.\n",++tt);
			continue;
		}
		
		rotate();
		if(same()) {
			printf("Pattern %d was reflected vertically and rotated 270 degrees.\n",++tt);
			continue;
		}
		
		printf("Pattern %d was improperly transformed.\n",++tt);
	}
	
	return 0;
}
