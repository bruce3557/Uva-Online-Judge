#include <stdio.h>
char notp[] = { 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1,
                0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1,
                1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1};

int n;
char used[20],ans[20]; 

void go(int now){

	int i;

	if(now >= n){
		if( notp[ans[n-1]+ans[0]] == 0 ){
			for(i=0;i<n-1;i++)
				printf("%d ",ans[i]);
			printf("%d\n",ans[n-1]);
		}
		return;
	}

	for(i=2;i<=n;i++)
		if(used[i] == 0 && notp[ans[now-1]+i] == 0){
			used[i] = 1;
			ans[now] = i;
			go(now+1);
			used[i] = 0;
		}

}

int main(){

	int i, c = 0;

	while(scanf("%d",&n) != EOF){
		if(c)	puts("");
		ans[0] = 1;
		printf("Case %d:\n",++c);
		go(1);
	}

	return 0;

}
