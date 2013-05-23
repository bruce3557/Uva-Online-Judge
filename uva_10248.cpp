#include <stdio.h>
#include <string.h>

int map[110][110],n,m;
int ind[110],out[110],ans[2000],len;
char used[110];

int go(int now) {
	if(out[now] == 0) {
		return 1;
	}
	/*printf("%d ",now);*/
	int i,t;
	if(now < 10 && used[now*10+now] == 0 && map[now][now*10+now]) {
		used[now*10+now] = 1;
		map[now][now*10+now]--;
		if(go(now*10+now)) {
			ans[len++] = now*10+now;
			return 1;
		}
		used[now*10+now] = 1;
		map[now][now*10+now]++;
	}
	t = now%10;
	printf("%d ",t);
	for(i=t*10;i<(t+1)*10;i++)
		if(used[i] == 0 && map[now][i]) {
			map[now][i]--;
			used[i] = 1;
			if(go(i)) {
				ans[len++] = i;
				return 1;
			}
			used[i] = 0;
			map[now][i]++;
		}
	/*if(used[t*10] == 0 && map[now][t*10]) {
		map[now][t*10]--;
		used[t*10] = 1;
		if(go(i)) {
			ans[len++] = i;
			return 1;
		}
		used[t*10] = 0;
		map[now][t*10]++;
	}*/
	for(i=n;i<=m;i++)
		if(used[i]==0 && map[now][i]) {
			map[now][i]--;
			used[i] = 1;
			if(go(i)) {
				ans[len++] = i;
				return 1;
			}
			used[i] = 0;
			map[now][i]++;
		}
	
}

int main() {

	int i,j;

	while(scanf("%d%d",&n,&m) != EOF) {
		memset(map,0,sizeof(map));
		memset(ind,0,sizeof(ind));
		memset(out,0,sizeof(out));
		memset(used,0,sizeof(used));
		
		for(i=n;i<=m;i++)
			for(j=n;j<=m;j++) {
				if(i < 10) {
					if(j >= 10)
						if(i == (j/10)) {
							map[i][j] = 1;
							out[i]++;
							ind[j]++;
						}
				} else {
					if(i == j && (i/10) == (i%10)) {
						map[i][j] = 1;
						continue;
					}
					
					if(j >= 10) {
						if((i%10) == (j/10)) {
							map[i][j] = 1;
							out[i]++;
							ind[j]++;
						}
					} else {
						if((i%10) == j) {
							map[i][j] = 1;
							out[i]++;
							ind[j]++;
						}
					}
				}
			}
		
		/*for(i=n;i<=m;i++,puts(""))
			for(j=n;j<=m;j++)
				printf("%d ",map[i][j]);*/
		
		len = 0;
		for(i=m;i>=n;i--)
			if(used[i] == 0) {
				used[i] = 1;
				go(i);
				ans[len++] = i;
				puts("");
			}
		
		/*for(i=len-1;i>=0;i--)
			printf("%d ",ans[i]);
		puts("");*/
		
		printf("%d",ans[len-1]);
		for(i=len-2;i>=0;i--) {
			if(ans[i]>=10) {
				if(ans[i]/10 == (ans[i+1]%10))
					printf("%d",ans[i]%10);
				else
					printf("%d",ans[i]);
			} else {
				if(ans[i] != (ans[i+1]%10))
					printf("%d",ans[i]);
			}
		}
		puts("");
	}
	
	return 0;
}
