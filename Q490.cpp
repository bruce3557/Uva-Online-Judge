#include <stdio.h>
#include <string.h>

int len[110],n;
char map[110][110];

int main() {
	int i,j,max;
	n = 0;
	while(gets(map[n]) != NULL)	n++;
	for(i=0;i<n;i++)
		len[i] = strlen(map[i]);
	max = 0;
	for(i=0;i<n;i++)
		if(max < len[i])
			max = len[i];
	for(i=0;i<max;i++) {
		for(j=n-1;j>=0;j--) {
			if(map[j][i] == '\0') {
				printf(" ");
				continue;
			}
			printf("%c",map[j][i]);
		}
		puts("");
	}

	return 0;
}
