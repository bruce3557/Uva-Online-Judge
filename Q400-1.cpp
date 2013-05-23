#include <stdio.h>
#include <string.h>
#include <algorithm>

struct node{
	char s[100];
	int len;
	bool operator < (node t) const {
		return strcmp(s,t.s) < 0;
	}
}file[1000];

int main(){
	int n,i,j,k,t;
	int col,max;
	while(scanf("%d",&n) != EOF){
		getchar();
		max = 0;
		for(i=0;i<n;i++){
			gets(file[i].s);
			t = file[i].len = strlen(file[i].s);
			if(max < t)
				max = t;
		}
		puts("------------------------------------------------------------");
		std::sort(file,file+n);
		if(max < 60){
			t = (60-max)/(max+2)+1;
			if(n%t == 0){
				col = n/t;
			} else {
				col = n/t+1;
			}
		} else {
			col = n;
		}
		for(i=0;i<col;i++,puts(""))
			for(j=i;j<n;j+=col){
				printf("%s",file[j].s);
				for(k=max-file[j].len;k>0;k--)
					printf(" ");
				if(j+col >= n)	continue;
				printf("  ");
			}
	}
	return 0;
}
