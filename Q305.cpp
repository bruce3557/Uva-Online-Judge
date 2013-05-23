#include <stdio.h>
#define MAX 14

struct node {
	int pre,next;
} people[MAX*2];

int main() {
	
	int i,j,n,m,ptr,num,tmp;
	int ans[MAX*2];
	char flag;
	
	for(i=1;i<2*MAX-1;i++)
		ans[i] = -1;
	ans[1] = 2;
	
	while(scanf("%d",&n) && n) {
		
		if(ans[n] != -1){
			printf("%d\n",ans[n]);
			continue;
		}
		
		n *= 2;
		m = n/2+1, flag = 0;
		
		while(1) {
			
			for(i=1;i<=n;i++)
				people[i] = (node) { i-1,i+1 };
		
			people[1].pre = n;
			people[n].next = 1;
			ptr = 1, num = n;
			
			while(1) {
				
				if(num <= n/2) {
					flag = 1;
					break;
				}
				
				tmp = m%num;
				
				for(i=0;i<tmp;i++)
					ptr = people[ptr].next;
				
				if(ptr <= n/2)	break;
				
				people[people[ptr].pre].next = people[ptr].next;
				people[people[ptr].next].pre = people[ptr].pre;
				ptr = people[ptr].next;
				num--;
				
			}
			
			if(flag)	break;
			
			m++;
			
		}
		
		ans[n/2] = m+1;
		printf("%d\n",m+1);
		
	}
	
	return 0;
}
