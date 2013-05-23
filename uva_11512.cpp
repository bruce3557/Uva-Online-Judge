#include <stdio.h>
#include <string.h>

char s[1010],sub[1010],anssub[1010],sub1[1010];
int n;

int main(){
	int t,st,ed,mid;
	int i,j,k,q;
	int max,max_times,times,times1;
	char flag;
	scanf("%d%*c",&t);
	while(t--){
		gets(s);
		n = strlen(s);
		st = 0, ed = n,max = max_times = 0;
		memset(sub,0,sizeof(sub));
		memset(sub1,0,sizeof(sub1));
		memset(anssub,0,sizeof(anssub));
		while(st < ed){
			mid = (st+ed)/2;
			for(i = flag = 0;i+mid<=n;i++){
				times = 0;
				for(j=i;j<i+mid;j++)
					sub[j-i] = s[j];
				sub[j] = '\0';
				if(flag == 1 && strcmp(sub1,sub) <= 0)	continue;
				for(j=0;j+mid<=n;j++){
					for(k=0,q=j;k<mid && sub[k] == s[q];k++,q++);
					if(k>=mid)	times++;
				}
				//printf("%s %d\n",sub,times);
				if(flag == 0 && times >= 2) {
					flag = 1;
					for(j=0;j<mid;j++)
						sub1[j] = sub[j];
					times1 = times;
				} else if(flag  == 1 && times >= 2 && strcmp(sub1,sub) > 0) {
					//printf("%d\n",strncmp(sub1,sub,mid));
					//printf("%s %s\n",sub1,sub);
					for(j=0;j<mid;j++)
						sub1[j] = sub[j];
					times1 = times;
				}
			}
			if(flag == 1){
				if(max < mid){
					max = mid;
					max_times = times1;
					for(i=0;i<max;i++)
						anssub[i] = sub1[i];
					anssub[i] = '\0';
				}
				st = mid+1;
			} else {
				ed = mid;
			}
		}
		if(max == 0){
			puts("No repetitions found!");
		} else {
			*(anssub+max) = '\0';
			printf("%s %d\n",anssub,max_times);
		}
	}
	return 0;
}
