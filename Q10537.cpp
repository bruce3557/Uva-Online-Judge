#include <stdio.h>
#include <string.h>
int n,num,path[100];
char used[100],map[100][100];
long long dis[100];

const long long MAX = (long long)9999999999999999LL;

int turn(char now) {
	if(now >= 'A' && now <= 'Z')	  return now-'A';
	else if(now >= 'a' && now <= 'z') return now-'a'+26;
}

int turn1(int now) {
	if(now < 26)	return now+'A';
	else			return now-26+'a';
}

int main() {
	int i,j,k,minptr,c=0;
	int st,ed;
	long long ans,tmp,left,right,mid,min;
	char a,b;
	
	while(scanf("%d",&n) && n != -1) {
		getchar();
		memset(used,0,sizeof(used));
		memset(map,0,sizeof(map));
		for(i=0;i<n;i++) {
			scanf("%c%*c%c%*c",&a,&b);
			j = turn(a);
			k = turn(b);
			map[j][k] = map[k][j] = 1;
		}
		scanf("%d%*c%c%*c%c",&num,&a,&b);
		
		st = turn(a);
		ed = turn(b);
		for(i=0;i<52;i++)
			dis[i] = MAX;
		dis[ed] = num;
		path[ed] = -1;
		
		for(i=0;i<52;i++) {
			min = MAX;
			for(j=0;j<52;j++)
				if(used[j] == 0 && min > dis[j]) {
					min = dis[j];
					minptr = j;
				}
			used[minptr] = 1;
			if(minptr == st)	break;
			
			if(minptr < 26) {
				left = 1, right = MAX;
				while(left < right) {
					mid = (left+right)/2;
					tmp = mid-(mid+19)/20;
					if(tmp == dis[minptr])
						right = mid;
					else if(tmp > dis[minptr])
						right = mid-1;
					else
						left = mid+1;
				}
				for(j=0;j<52;j++)
					if(map[minptr][j] && dis[j] > right) {
						dis[j] = right;
						path[j] = minptr;
					}
			} else {
				for(j=0;j<52;j++)
					if(map[minptr][j] && dis[j] > dis[minptr]+1) {
						dis[j] = dis[minptr]+1;
						path[j] = minptr;
					}
			}
		}
		printf("Case %d:\n",++c);
		printf("%lld\n",dis[st]);
		for(i=st;i!=ed;i=path[i])
			printf("%c-",turn1(i));
		printf("%c\n",turn1(i));
	}
	
	return 0;
}
