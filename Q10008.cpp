#include <stdio.h>
#include <string.h>
#include <algorithm>

struct node {
	char x;
	int count;
	bool operator < (node t) const {
		return count > t.count || (count == t.count && x < t.x);
	}
}ans[100];

char s[1000010];

int main() {

	int t,n,i;
	for(i=0;i<26;i++) {
		ans[i].x = 'A'+i;
		ans[i].count = 0;
	}

	scanf("%d%*c",&t);
	while(t--) {
		gets(s);
		n = strlen(s);
		for(i=0;i<n;i++) {
			if(s[i] >= 'A' && s[i] <= 'Z')
				ans[s[i]-'A'].count++;
			else if(s[i] >= 'a' && s[i] <= 'z')
				ans[s[i]-'a'].count++;
		}
	}
	
	std::sort(ans,ans+26);
	for(i=0;i<26;i++)
		if(ans[i].count > 0)
			printf("%c %d\n",ans[i].x,ans[i].count);
	
	return 0;
}
