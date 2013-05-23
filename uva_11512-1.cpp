#include <stdio.h>
#include <string.h>

int main(){
	
	int t,st,ed,mid;
	int i,j,k,q,n;
	int max,max_times,times,times1;
	char flag,*sub,*sub1,*anssub,s[1010];
	
	scanf("%d%*c",&t);
	
	while(t--){
		
		gets(s);
		n = strlen(s);
		
		st = 0, ed = n,max = max_times = 0;
		while(st < ed){
		
			mid = (st+ed)/2;
			
			for(i = flag = 0;i+mid<=n;i++) {
			
				times = 0;
				sub = s+i;
				if(flag == 1 && strncmp(sub1,sub,mid) <= 0)	continue;
				for(j=0;j+mid<=n;j++) {
					for(k=0,q=j;k<mid && *(sub+k) == s[q];k++,q++);
					if(k>=mid)	times++;
				}
				
				if(flag == 0 && times >= 2) {
					flag = 1;
					sub1 = sub;
					times1 = times;
				} else if(flag  == 1 && times >= 2 && strncmp(sub1,sub,mid) > 0) {
					sub1 = sub;
					times1 = times;
				}
				
			}
			
			if(flag == 1) {
				if(max < mid) {
					max = mid;
					max_times = times1;
					anssub = sub1;
				}
				st = mid+1;
			} else {
				ed = mid;
			}
			
		}
		
		if(max == 0) {
			puts("No repetitions found!");
		} else {
			*(anssub+max) = '\0';
			printf("%s %d\n",anssub,max_times);
		}
		
	}
	
	return 0;
}
