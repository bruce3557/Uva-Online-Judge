#include <stdio.h>
#include <string.h>
#include <set>

using std::set;

struct node {
	char name[40];
	int num;
	
	bool operator < (const node &t) const {
		return (strcmp(name, t.name) < 0);
	}
};

int main() {
	int t,c=0;
	char temp[40];
	
	scanf("%d",&t);
	gets(temp);
	gets(temp);
	
	while(t--) {
		if(c)	puts("");
		else	++c;
		int total = 0;
		set<node> Q;
		while( gets(temp) && strcmp(temp,"") ) {
			++total;
			node tp;
			strcpy(tp.name, temp);
			
			set<node>::iterator it = Q.find(tp);
			if( it == Q.end() ) {
				tp.num = 1;
				Q.insert(tp);
				continue;
			}
			tp.num = (it->num)+1;
			Q.erase(tp);
			Q.insert(tp);
		}
		
		for(set<node>::iterator it=Q.begin();it != Q.end();++it) {
			double ans = (double)(it->num)/total;
			printf("%s %.4lf\n", it->name,ans*100);
		}
	}
	return 0;
}
