#include <stdio.h>
#include <string.h>

int s[510],n,m;
long long con[510],sum,average;
bool cut[510];

bool test(int num) {
	int len,i,j;
	
	i = n, len = 0;
	while(i > 0) {
		for(j=i-1;j>=0;j--)
			if(con[i]-con[j] > num)
				break;
		
		i = j+1;
		len++;
	}
	
	return len <= m;
}

int main() {

	int t,max,i,j;
	long long st,ed,mid;
	
	scanf("%d",&t);
	while(t--) {
		
		scanf("%d%d",&n,&m);
		con[0] = s[0] = sum = max = 0;
		memset(cut,0,sizeof(bool)*(n+1));
		
		for(i=1;i<=n;i++) {
			scanf("%d",s+i);
			con[i] = con[i-1]+s[i];
			sum += s[i];
			if(max < s[i])	max = s[i];
		}
		
		average = sum/n;
		if(average < max) average = max;
		
		st = average, ed = sum;
		while(st < ed) {
			mid = (st+ed)/2;
			if(test(mid)) {
				ed = mid;
			} else {
				st = mid+1;
			}
		}
		
		printf("%lld\n",ed); 
		m--;
		for(i=n;i>0;) {
			for(j=i-1;j>=0;j--)
				if(con[i]-con[j] > ed) {
					m--;
					break;
				}
			cut[j+1] = 1;
			i = j+1;
		}
		i = 1;
		while(m > 0) {
			if(cut[i] == 0) {
				cut[i] = 1;
				m--;
			}
			i++;
		}
		for(i=1;i<n;i++) {
			printf("%d ",s[i]);
			if(cut[i])
				printf("/ ");
		}
		printf("%d\n",s[n]);
	}

	return 0;
}
