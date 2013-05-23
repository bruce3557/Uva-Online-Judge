#include <stdio.h>
int n,s[100],ans;

void go(int now){
	int i,tmp;
	if(now >= n){
		for(i=0;i<n;i++)
			printf("%d ",s[i]);
		puts("");
		for(i=0;i<n-1;i++)
			if(s[i] > s[i+1])
				return;
		ans++;
		return;
	}
	for(i=0;i<n-1;i++){
		tmp = s[i];
		s[i] = s[i+1];
		s[i+1] = tmp;
		go(now+1);
		tmp = s[i];
		s[i] = s[i+1];
		s[i+1] = tmp;
	}
}

int main(){
	int t = 0;
	int i,j;
	while(scanf("%d",&n) && n){
		for(i=0;i<n;i++)
			scanf("%d",&s[i]);
		ans = 0;
		go(0);
		printf("There are %d swap maps for input data set %d.\n",ans,++t);
	}
	return 0;
}
