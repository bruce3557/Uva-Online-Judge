#include <stdio.h>
#include <algorithm>
char s[500],d[500],used[50],u[50],ww[50];
int len,lis[500],num[500],ans,max;

void go(int now){
	if(now >= max){
		ans++;
		return;
	}
	int i;
	for(i=0;i<len;i++)
		if(d[i]*4 >= ww[now-1]*5 && u[i] == 0){
			u[i] = 1;
			ww[now] = d[i];
			go(now+1);
			u[i] = 0;
		}
}

int main(){
	int i,j,t;
	scanf("%d%*c",&t);
	while(t--){
		memset(lis,0,sizeof(lis));
		memset(num,0,sizeof(num));
		memset(used,0,sizeof(used));
		memset(u,0,sizeof(u));
		memset(ww,0,sizeof(ww));
		gets(s);
		len = 0;
		for(i=0;s[i] != '\0';i++)
			if(s[i] >= 'A' && s[i] <= 'Z' && used[s[i]-'A'] == 0){
				d[len++] = s[i]-'A'+1;
				used[s[i]-'A'] = 1;
			}
		d[len] = '\0';
		std::sort(d,d+len);
		for(i=0;i<len;i++)
			lis[i] = 1;
		for(i=0;i<len;i++)
			for(j=0;j<i;j++)
				if(d[j]*5 <= d[i]*4 && lis[j]+1 >= lis[i]){
					lis[i] = lis[j]+1;
					num[lis[i]]++;
				}
		max = ans = 0;
		for(i=0;i<len;i++)
			if(max < lis[i])
				max = lis[i];
		for(i=0;i<len;i++){
			u[i] = 1;
			ww[0] = d[i];
			go(1);
			u[i] = 0;
		}
		printf("%d %d\n",max,ans);
	}
}
