#include <stdio.h>
#include <string.h>

char ch[] = {'_','a','b','c','d','e','f','g','h','i','l','m','n','o','p','r','s','t','u'};
int m,num[22],len,use[22],n;
char input[1010],ans[22],used[22];

bool go(int now,int sum) {
	if(sum > m)	return 0;
	int i;
	if(now >= n) {
		if(sum == m) {
			int k = now;
			for(i=0;i<19;i++)
				if(num[i] == 0)
					ans[k++] = i;
			return 1;
		} else
			return 0;
	}
	for(i=0;i<n;i++)
		if(used[use[i]] == 0) {
			used[use[i]] = 1;
			ans[now] = ch[use[i]];
			if(go(now+1,sum+(now+1)*num[use[i]]))	return 1;
			used[use[i]] = 0;
		}
	return 0;
}

int main() {
	int i,j;
	
	while(scanf("%s",input) && input[0] != '*') {
		scanf("%d",&m);
		memset(num,0,sizeof(num));
		memset(used,0,sizeof(used));
		len = strlen(input);
		n = 0;
		for(i=0;i<len;i++) {
			if(input[i] == '_') {
				num[0]++;
				if(num[0] == 1)	use[n++] = 0;
			} else if(input[i] >= 'a' && input[i] <= 'i') {
				num[input[i]-'a'+1]++;
				if(num[input[i]-'a'+1] == 1)	use[n++] = input[i]-'a'+1;
			} else if(input[i] >= 'l' && input[i] <= 'p') {
				num[input[i]-'l'+10]++;
				if(num[input[i]-'l'+10] == 1)	use[n++] = input[i]-'l'+10;
			} else {
				num[input[i]-'r'+15]++;
				if(num[input[i]-'r'+15] == 1)	use[n++] = input[i]-'r'+15;
			}
		}
		go(0,0);
		for(i=0;i<19;i++)
			printf("%c",ans[i]);
		puts("");
	}

	return 0;
}
