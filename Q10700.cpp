#include <stdio.h>
#include <string.h>

int s[20];
char op[20],ss[500];

long long stackoa[50],topoa;
char stackop[50],topop,tt;

int main() {
	int t;
	int i,j,n,len,tt;
	long long max,min,tmp;
	
	scanf("%d",&t);
	while(t--) {	
		scanf("%s",ss);
		n = tt = 0;
		len = strlen(ss);
		for(i=0;i<len;i++) {
			if(ss[i] >= '0' && ss[i] <= '9') {
				tt = tt*10+ss[i]-'0';
			} else if(ss[i] == '+' || ss[i] == '*') {
				s[n] = tt;
				tt = 0;
				op[n] = ss[i];
				n++;
			}
		}
		s[n] = tt;
		
		topop = topoa = 0;
		stackoa[topoa++] = s[0];
		for(i=0;i<n;i++) {
			if(op[i] == '+') {
				stackop[topop++] = op[i];
				stackoa[topoa++] = s[i+1];
			} else if(op[i] == '*') {
				while(topop > 0 && stackop[topop-1] == '+') {
					topop--;
					tmp = stackoa[--topoa];
					tmp += stackoa[--topoa];
					stackoa[topoa++] = tmp;
				}
				stackop[topop++] = op[i];
				stackoa[topoa++] = s[i+1];
			}
		}
		
		while(topop > 0) {
			if(stackop[topop-1] == '+') {
				topop--;
				tmp = stackoa[--topoa];
				tmp += stackoa[--topoa];
				stackoa[topoa++] = tmp;
			} else if(stackop[topop-1] == '*') {
				topop--;
				tmp = stackoa[--topoa];
				tmp *= stackoa[--topoa];
				stackoa[topoa++] = tmp;
			}
		}
		max = stackoa[0];
		
		topop = topoa = 0;
		stackoa[topoa++] = s[0];
		for(i=0;i<n;i++) {
			if(op[i] == '*') {
				stackop[topop++] = op[i];
				stackoa[topoa++] = s[i+1];
			} else if(op[i] == '+') {
				while(topop > 0 && stackop[topop-1] == '*') {
					topop--;
					tmp = stackoa[--topoa];
					tmp *= stackoa[--topoa];
					stackoa[topoa++] = tmp;
				}
				stackop[topop++] = op[i];
				stackoa[topoa++] = s[i+1];
			}
		}
		
		while(topop > 0) {
			if(stackop[topop-1] == '+') {
				topop--;
				tmp = stackoa[--topoa];
				tmp += stackoa[--topoa];
				stackoa[topoa++] = tmp;
			} else if(stackop[topop-1] == '*') {
				topop--;
				tmp = stackoa[--topoa];
				tmp *= stackoa[--topoa];
				stackoa[topoa++] = tmp;
			}
		}
		min = stackoa[0];
		
		printf("The maximum and minimum are %lld and %lld.\n",max,min);
	}
	
	return 0;
}
