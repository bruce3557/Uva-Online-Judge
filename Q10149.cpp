#include <stdio.h>
#include <string.h>

int score[13];
int round[13][5];

bool Input() {
	if(scanf("%d",&round[0][0]) == EOF)	return false;
	for(int i=1;i<5;i++)
		scanf("%d",&round[0][i]);
	for(int i=1;i<13;i++)
		for(int j=0;j<5;j++)
			scanf("%d",&round[i][j]);
}

int main() {

	while( Input() ) {
		
	}

	return 0;
}
