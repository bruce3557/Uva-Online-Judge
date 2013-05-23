#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using std::set;

int n,m;
int len;
char s1[400], s2[400];

struct node {
	char s[400];
	
	node(){};
	node(char *_s, int len) {
		strncpy(s, _s,len);
		s[len] = '\0';
	}
	
	bool operator < (const node &t) const {
		return strcmp(s, t.s) < 0;
	}
} ans[400];

inline bool read() {
	if(gets(s1) == NULL)	return false;
	gets(s2);
	char str[400];
	gets(str);
	return true;
}

inline void Solve() {
	static bool c=false;
	if(c)	puts("");
	c = true;
	n = strlen(s1);
	m = strlen(s2);
	
	set<node> answer;
	int k;
	for(k=(n<m)?n:m;k>0;--k) {
		bool suc = false;
		for(int i=0;i+k<=n;++i)
			for(int j=0;j+k <= m;++j) {
				if( !strncmp(s1+i,s2+j,k) ) {
					answer.insert(node(s1+i, k));
					suc = true;
				}
			}
		if(suc)	break;
	}
	
	if(k <= 0)	puts("No common sequence.");
	else {
		for(set<node>::iterator it=answer.begin();it != answer.end();++it)
			printf("%s\n",it->s);
	}
}

int main() {
	while( read() )	Solve();
	return 0;
}
