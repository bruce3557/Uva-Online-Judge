#include <stdio.h>
#define MAX 200

struct node {
	int pre,next;
} people[MAX];

int main() {
	
	int i,j,n,m,ptr,num,tmp,kill;
	int ans[MAX];
	char flag;
	
	for(i=1;i<MAX;i++)
		ans[i] = -1;
	ans[1] = 2;
	
	while(scanf("%d",&n) && n) {
		
		if(ans[n] != -1){
			printf("%d\n",ans[n]);
			continue;
		}
		
		m = 1, flag = 0;
		
		while(1) {
			
			for(i=2;i<=n;i++)
				people[i] = (node) { i-1,i+1 };
		
			people[2].pre = n;
			people[n].next = 2;
			ptr = 2, num = n-1;
			
			while(1) {
				
				if(num <= 1) {
					flag = 1;
					break;
				}
				
				for(i=1;i<m;i++)
					ptr = people[ptr].next;
				
				if(ptr == 2)	break;
								
				people[people[ptr].pre].next = people[ptr].next;
				people[people[ptr].next].pre = people[ptr].pre;
				ptr = people[ptr].next;
				num--;
				
			}
			
			if(flag)	break;
			
			m++;
			
		}
		
		ans[n] = m;
		printf("%d\n",m);
		
	}
	
	return 0;
}
