#include <stdio.h>

int n,now,cnt;
char s1[100],s2[100],ans[100];

void go(int st,int ed){
	if(st>=ed){
		now--;
		return;
	}
	
	int i,t = now;
	for(i=st;i<ed;i++)
		if(s1[now] == s2[i])
			break;
	now++;
	go(st,i);
	now++;
	go(i+1,ed);
	ans[cnt++] = s1[t];
}

int main(){
	int t,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d ",&n);
		scanf("%s %s",s1,s2);
		now = cnt = 0;
		go(0,n);
		ans[n] = '\0';
		puts(ans);
	}
	return 0;
}
