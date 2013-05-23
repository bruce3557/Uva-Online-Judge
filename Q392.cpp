#include <stdio.h>

int s[10];

int main() {
	int i;
	
	while(scanf("%d",&s[8]) != EOF) {
		for(i=7;i>=0;i--)
			scanf("%d",s+i);
		for(i=8;i>=0 && s[i] == 0;i--);
		if(i < 0) {
			puts("0");
			continue;
		}
		
		if(i == 0) {
			if(s[i] == 1)
				printf("1");
			else if(s[i] == -1)
				printf("-1");
			else if(s[i] < 0)
				printf("%d",s[i]);
			else
				printf("%d",s[i]);
		} else if(i == 1) {
			if(s[i] == 1)
				printf("x");
			else if(s[i] == -1)
				printf("-x");
			else if(s[i] < 0)
				printf("%dx",s[i]);
			else
				printf("%dx",s[i]);
		} else {
			if(s[i] == 1)
				printf("x^%d",i);
			else if(s[i] == -1)
				printf("-x^%d",i);
			else
				printf("%dx^%d",s[i],i);
		}
		i--;
		
		while(i >= 0) {
			if(s[i]) {
				if(i == 0) {
					if(s[i] == 1)
						printf(" + 1");
					else if(s[i] == -1)
						printf(" - 1");
					else if(s[i] < 0)
						printf(" - %d",-s[i]);
					else
						printf(" + %d",s[i]);
				} else if(i == 1) {
					if(s[i] == 1)
						printf(" + x");
					else if(s[i] == -1)
						printf(" - x");
					else if(s[i] < 0)
						printf(" - %dx",-s[i]);
					else
						printf(" + %dx",s[i]);
				} else {
					if(s[i] == 1)
						printf(" + x^%d",i);
					else if(s[i] == -1)
						printf(" - x^%d",i);
					else if(s[i] < 0)
						printf(" - %dx^%d",-s[i],i);
					else
						printf(" + %dx^%d",s[i],i);
				}
			}
			i--;
		}
		puts("");
	}

	return 0;
}
