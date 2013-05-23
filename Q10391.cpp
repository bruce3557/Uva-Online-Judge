#include <stdio.h>
#include <string.h>

struct node {
	char s[500];
	int len;
} word[150000];

int n;
int f[30];

bool Find(char *s) {
	int now = s[0]-'a';
	int st,ed,mid,tmp;
	st = f[now];
	ed = f[now+1];
	while(st < ed) {
		mid = (st+ed)/2;
		tmp = strcmp(word[mid].s,s);
		if(tmp == 0)
			return true;
		else if(tmp < 0)
			st = mid+1;
		else
			ed = mid;
	}
	
	return false;
}

bool test(int num) {
	int now = word[num].s[0]-'a';
	
	if(word[num].len <= 1)	return false;
	
	int i,j,k;
	char find[500];
	for(i=f[now];i<num && i<f[now+1];i++) {
		for(j=0;j<word[i].len && word[i].s[j] == word[num].s[j];j++);
		if(j >= word[i].len) {
			for(k=word[i].len;k<word[num].len;k++)
				find[k-word[i].len] = word[num].s[k];
			find[k-word[i].len] = '\0';
			if(Find(find) == true)	return true;
		}
	}
	
	return false;
}

int main() {

	int i,j;
	
	n = 0;
	while(gets(word[n].s) != NULL) {
		word[n].len = strlen(word[n].s);
		n++;
	}

	for(i=0;i<26;i++)
		f[i] = -1;
	for(i=0;i<n;i++)
		if(f[word[i].s[0]-'a'] == -1)
			f[word[i].s[0]-'a'] = i;
	f[26] = n;
	for(i=25;i>=0;i--)
		if(f[i] == -1)
			f[i] = f[i+1];
	
	for(i=0;i<n;i++)
		if(test(i) == true)
			puts(word[i].s);
	
	return 0;
}
