#include <stdio.h>
#include <string.h>
#include <algorithm>

struct node {

	char num[200];
	int len;
	
	bool operator < (node t) const {
		return strcmp(num,t.num) < 0;
	}
	
	void getnum() {
		scanf("%s",num);
		len = strlen(num);
	}
	
} phone[10010];

int main() {

	int t,n,i,j;
	char flag;
	
	scanf("%d",&t);
	
	while(t--) {
		
		scanf("%d%*c",&n);
		
		for(i=0;i<n;i++)
			phone[i].getnum();
		
		std::sort(phone,phone+n);
		
		flag = 0;
		
		for(i=0;i<n-1;i++) {
			for(j=0;j<phone[i].len && phone[i].num[j] == phone[i+1].num[j];j++);
			if(j >= phone[i].len) {
				flag = 1;
				break;
			}
		}
		
		if(flag)	puts("NO");
		else		puts("YES");
		
	}

	return 0;
}
