#include <stdio.h>
#include <string.h>
#include <algorithm>

int n;
char temp[300000];
struct node {
	int order;
	char s[50];
	
	bool operator < (const node &t)const {
		return order < t.order;
	}
}num[100000];

int main() {
	int t;
	char c;
	int cc=0;
	
	scanf("%d%*c",&t);
	
	while(t--) {
		if(cc)	puts("");
		else	cc=1;
		gets(temp);
		n = 0;
		gets(temp);
		int len = strlen(temp);
		int ptr=0;
		while(ptr < len) {
			for(;ptr < len && temp[ptr] == ' ';++ptr);
			if(ptr >= len)	break;
			sscanf(temp+ptr,"%d",&num[n].order);
			++n;
			for(;ptr < len && temp[ptr] != ' ';++ptr);
			
		}
		
		for(int i=0;i<n;++i)
			scanf("%s",&num[i].s);
		scanf("%*c");
		std::sort(num,num+n);
		for(int i=0;i<n;++i)
			puts(num[i].s);
	}
	
	return 0;
}
