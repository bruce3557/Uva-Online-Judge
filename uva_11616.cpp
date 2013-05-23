#include <stdio.h>
#include <string.h>

char s[50],ans[100];

int judge(char s[10]) {
	if(s[0] == 'I' || s[0] == 'V' || s[0] == 'X' || s[0] == 'L' || s[0] == 'C' || s[0] == 'D' || s[0] == 'M')
		return 1;
	else
		return 2;
}

int main() {
	int i,j,n,sum,len;
	
	while(scanf("%s",s) != EOF) {
		int mode = judge(s);
		sum = 0;
		n = strlen(s);
		if(mode == 1) {
			for(i=n-1;i>=0;) {
				if(s[i] == 'I') {
					sum++;
					i--;
				} else if(s[i] == 'V') {
					if(i > 0 && s[i-1] == 'I') {
						sum += 4;
						i -= 2;
					} else {
						sum += 5;
						i--;
					}
				} else if(s[i] == 'X') {
					if(i > 0 && s[i-1] == 'I') {
						sum += 9;
						i -= 2;
					} else {
						sum += 10;
						i--;
					}
				} else if(s[i] == 'L') {
					if(i > 0 && s[i-1] == 'X') {
						sum += 40;
						i -= 2;
					} else {
						sum += 50;
						i--;
					}
				} else if(s[i] == 'C') {
					if(i > 0 && s[i-1] == 'X') {
						sum += 90;
						i -= 2;
					} else {
						sum += 100;
						i--;
					}
				} else if(s[i] == 'D') {
					if(i > 0 && s[i-1] == 'C') {
						sum += 400;
						i -= 2;
					} else {
						sum += 500;
						i--;
					}
				} else {
					if(i > 0 && s[i-1] == 'C') {
						sum += 900;
						i -= 2;
					} else {
						sum += 1000;
						i--;
					}
				}
			}
			printf("%d\n",sum);
		} else {
			len = sum = 0;
			for(i=0;i<n;i++)
				sum = sum*10+s[i]-'0';
			i=0;
			while(sum > 0) {
				int x = sum % 10;
				if(i == 0) {
					if(x == 4) {
						ans[len++] = 'V';
						ans[len++] = 'I';
					} else if(x == 9) {
						ans[len++] = 'X';
						ans[len++] = 'I';
					} else if(x < 4) {
						for(j=0;j<x;j++)
							ans[len++] = 'I';
					} else {
						for(j=0;j<x-5;j++)
							ans[len++] = 'I';
						ans[len++] = 'V';
					}
				} else if(i == 1) {
					if(x == 4) {
						ans[len++] = 'L';
						ans[len++] = 'X';
					} else if(x == 9) {
						ans[len++] = 'C';
						ans[len++] = 'X';
					} else if(x < 4) {
						for(j=0;j<x;j++)
							ans[len++] = 'X';
					} else {
						for(j=0;j<x-5;j++)
							ans[len++] = 'X';
						ans[len++] = 'L';
					}
				} else if(i == 2) {
					if(x == 4) {
						ans[len++] = 'D';
						ans[len++] = 'C';
					} else if(x == 9) {
						ans[len++] = 'M';
						ans[len++] = 'C';
					} else if(x < 4) {
						for(j=0;j<x;j++)
							ans[len++] = 'C';
					} else {
						for(j=0;j<x-5;j++)
							ans[len++] = 'C';
						ans[len++] = 'D';
					}
				} else {
					for(j=0;j<x;j++)
						ans[len++] = 'M';
				}
				sum /= 10;
				i++;
			}
			for(i=len-1;i>=0;i--)
				printf("%c",ans[i]);
			puts("");
		}
	}
	
	return 0;
}
