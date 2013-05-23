#include <stdio.h>
#include <string.h>
#include <algorithm>

int n,ansp[100010];

class node{
	public:
		int l,r;
		bool operator < (node t) const{
			return (l < t.l || (l == t.l && r < t.r));
		}
}s[100010];

int main(){
	
	int t,c=0,m;
	int i;
	int cur_left,ans,pre,max,max_ptr;
	char flag;
	
	scanf("%d",&t);
	
	while(t--){
		
		if(c)	puts("");
		else	c = 1;
		
		scanf("%d",&m);

		for(n=0;;n++){
			scanf("%d%d",&s[n].l,&s[n].r);
			if(s[n].l == 0 && s[n].r == 0)	break;
		}

		std::sort(s,s+n);
		pre = -1;
		cur_left = ans = flag = 0;
		max = -99999999;

		while(1){
			for(i=pre+1;i<n && s[i].l <= cur_left;i++)
				if(s[i].r > max){
					max = s[i].r;
					max_ptr = i;
				}
				
			if(max_ptr >= n || pre == max_ptr)	break;
			pre = ansp[ans++] = max_ptr;
			cur_left = s[max_ptr].r;
			if(cur_left >= m){
				flag = 1;
				break;
			}
		}

		if(flag == 0)	puts("0");
		else{
			printf("%d\n",ans);
			for(i=0;i<ans;i++)
				printf("%d %d\n",s[ansp[i]].l,s[ansp[i]].r);
		}

	}
	return 0;
}
