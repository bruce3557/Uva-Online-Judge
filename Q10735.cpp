#include <stdio.h>
#include <string.h>

struct node {
	int a,b;
} de[1010],ude[1010];

int n,m,numd,numu,total,numofe;
int in[110],out[110],und[110],ans[510],map[110][110],res[620][620];

int abs(int x) {
	if(x < 0)	return -x;
	return x;
}

int MaxFlow(int st,int ed) {
	int pre[620],i,j,k,sum=0,q[620];
	
	while(1) {
		for(i=0;i<=ed;i++)
			pre[i] = -1;
		q[0] = st;
		i = 0, j = 1;
		while(i < j) {
			if(q[i] == ed)	break;
			for(k=0;k<=ed;k++)
				if(pre[k] == -1 && res[q[i]][k] > 0) {
					pre[k] = q[i];
					q[j++] = k;
				}
			i++;
		}
		if(i >= j)	return sum;
		sum++;
		for(k=ed;k!=st;k=pre[k]) {
			res[pre[k]][k]--;
			res[k][pre[k]]++;
		}
	}
}

void go(int now) {
	for(int i=1;i<=n;i++)
		if(map[now][i] > 0)	{
			map[now][i]--;
			go(i);
		}
	ans[numofe++] = now;
}

int main() {
	int i,j,k,t,sum,goal,qq=0;
	char c;
	
	scanf("%d",&t);
	while(t--) {
		if(qq)	puts("");
		else	qq = 1;
	
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(und,0,sizeof(und));
		memset(map,0,sizeof(map));
		memset(res,0,sizeof(res));
		
		scanf("%d%d",&n,&m);
		
		numd = numu = 0;
		for(i=0;i<m;i++) {
			scanf("%d %d %c",&j,&k,&c);
			if(c == 'U') {
				und[j]++;
				und[k]++;
				ude[numu++] = (node){j,k};
			} else {
				out[j]++;
				in[k]++;
				de[numd++] = (node){j,k};
			}
		}
		
		for(i=1;i<=n && und[i]>=abs(in[i]-out[i]) && (in[i]+out[i]+und[i])%2==0;i++);
		if(i <= n) {
			puts("No euler circuit exist");
			continue;
		}
		
		goal = numofe = 0;
		for(i=1;i<=n;i++)
			goal += abs(in[i]-out[i]+und[i]);
		goal /= 2;
			
		total = numu+n;							//ºc¹Ï
		for(i=0;i<numu;i++) {
			res[i][numu+ude[i].a]++;
			res[i][numu+ude[i].b]++;
		}
		for(i=1;i<=n;i++)
			if(in[i]-out[i]+und[i] > 0)
				res[numu+i][total+2] = (in[i]-out[i]+und[i])/2;
		for(i=0;i<numu;i++)
			res[total+1][i] = 1;
		total += 2;
		sum = MaxFlow(total-1,total);			//¶]flow
		
		if(sum != goal) {
			puts("No euler circuit exist");
			continue;
		}
		
		for(i=0;i<numd;i++)						//ºceuler circuit¹Ï
			map[de[i].a][de[i].b]++;
		
		for(i=0;i<numu;i++)
			for(j=1;j<=n;j++)
				if(res[j+numu][i] > 0) {
					if(ude[i].a == j)
						map[ude[i].a][ude[i].b]++;
					else
						map[ude[i].b][ude[i].a]++;
				}
		go(1);									//¶]euler circuit
		
		if(numofe-1 != numd+numu)
			puts("No euler circuit exist");
		else {
			for(i=numofe-1;i>0;i--)
				printf("%d ",ans[i]);
			printf("%d\n",ans[i]);
		}
	}
	
	return 0;
}
