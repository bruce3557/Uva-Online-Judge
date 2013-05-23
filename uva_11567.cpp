#include <stdio.h>
#include <map>
using namespace std;
long long n,minn;
struct node{
	long long now,cnt;
}q[100000];
int main(){
	int i,j;
	map<long long, long long> s;
	while(scanf("%lld",&n) != EOF){
		if(n == 0){
			puts("0");
			continue;
		}
		s.clear();
		s[n] = 1;
		i = 0, q[0].cnt = 1, j = 1;
		q[0].now = n;
		minn = 99999999;
		while(i < j){
			if(q[i].now == 1){
				if(minn > q[i].cnt)
					minn = q[i].cnt;
				i++;
				continue;
			}
			
			if(q[i].now % 2 == 0){
				if(s[q[i].now/2] == 0){
					s[q[i].now/2] = q[i].cnt+1;
					q[j++] = (node){q[i].now/2,q[i].cnt+1};
				} else if(q[i].cnt+1 < s[q[i].now/2]){
					s[q[i].now/2] = q[i].cnt+1;
					q[j++] = (node){q[i].now/2,q[i].cnt+1};
				}
			} else {
				if(s[(q[i].now+1)/2] == 0){
					s[(q[i].now+1)/2] = q[i].cnt+2;
					q[j++] = (node){(q[i].now+1)/2,q[i].cnt+2};
				} else if(q[i].cnt+2 < s[(q[i].now+1)/2]){
					s[(q[i].now+1)/2] = q[i].cnt+2;
					q[j++] = (node){(q[i].now+1)/2,q[i].cnt+2};
				}
				if(s[(q[i].now-1)/2] == 0){
					s[(q[i].now-1)/2] = q[i].cnt+2;
					q[j++] = (node){(q[i].now-1)/2,q[i].cnt+2};
				} else if(q[i].cnt+2 < s[q[i].now/2]){
					s[q[i].now/2] = q[i].cnt+2;
					q[j++] = (node){q[i].now/2,q[i].cnt+2};
				}
			}
			i++;
		}
		printf("%lld\n",minn);
	}
	return 0;
}
