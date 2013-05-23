#include <stdio.h>
#include <string.h>
#define MAX 1000000

char s[MAX+10],sub[110],used[MAX+10];
int n,sublen,len;
int pos[MAX+10],posC[110],tp[110];

int find(int& now,int& last) {
	int i,j;
	
	if(sub[now] >= 'a' && sub[now] <= 'z')
		i = sub[now]-'a'+26;
	else if(sub[now] >= 'A' && sub[now] <= 'Z')
		i = sub[now]-'A';
	
	for(j=posC[i];j != -1 && pos[j] < n && s[pos[j]] == sub[now];j++)
		if(last < pos[j] && used[pos[j]] == 0) {
			posC[i] = j;
			used[pos[j]] = 1;
			return pos[j];
		}
	
	return -1;
}

int main() {

	int i,j;
	int q,ptr,st,ed,tmp,last;
	
	while(gets(s) != NULL) {
		n = strlen(s);
		scanf("%d%*c",&q);
		
		memset(posC,0,sizeof(posC));
		memset(pos,0,sizeof(pos));
		
		for(i=0;i<100;i++)
			posC[i] = -1;
		
		for(i='A';i<='Z';i++) {
			tmp = i-'A';
			for(j=0;j<n;j++)
				if(s[j] == i) {
					if(posC[tmp] == -1)
						posC[tmp] = len;
					pos[len++] = j;
				}
		}
		for(i='a';i<='z';i++) {
			tmp = i-'a'+26;
			for(j=0;j<n;j++)
				if(s[j] == i) {
					if(posC[tmp] == -1)
						posC[tmp] = len;
					pos[len++] = j;
				}
		}
		for(i=0;i<52;i++)
			tp[i] = posC[i];
		
		while(q--) {
			gets(sub);
			sublen = strlen(sub);
			memset(used,0,sizeof(char)*(n+1));
			
			for(i=0;i<52;i++)
				posC[i] = tp[i];
			last= -1;
			for(i=0;i<sublen;i++) {
				ptr = find(i,last);
				if(ptr == -1)	break;
				
				last = ptr;
				if(i == 0)
					st = ptr;
				if(i == sublen-1)
					ed = ptr;
			}
			
			if(i >= sublen) {
				printf("Matched %d %d\n",st,ed);
			} else {
				puts("Not matched");
			}
		}
	}

	return 0;
}
