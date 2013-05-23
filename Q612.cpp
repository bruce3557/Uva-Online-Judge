#include <stdio.h>
#include <string.h>
#include <algorithm>

struct node {
	char s[200];
	int count,len,index;
	
	void getS() {
		scanf("%s",s);
	}
	
	void getlen() {
		len = strlen(s);
	}
	
	void getIndex(int i) {
		index = i;
	}
	
	void countInversion() {
		int i,j,ans=0;
		for(i=0;i<len-1;i++)
			for(j=i+1;j<len;j++)
				if(s[i] > s[j])
					ans++;
		count = ans;
	}
	bool operator < (node t) const {
		return count < t.count || (count == t.count && index < t.index);
	}
}DNA[100];

int main() {

	int t,i,j;
	int n,m,c=0;
	
	scanf("%d",&t);
	while(t--) {
		if(c)	puts("");
		else	c = 1;
		scanf("%d%d",&n,&m);
		
		for(i=0;i<m;i++) {
			DNA[i].getS();
			DNA[i].getlen();
			DNA[i].countInversion();
			DNA[i].getIndex(i);
		}
		
		std::sort(DNA,DNA+m);
		
		for(i=0;i<m;i++)
			puts(DNA[i].s);
		
	}

	return 0;
}
