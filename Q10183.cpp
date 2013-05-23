#include <stdio.h>
#include <string.h>

int n;
struct node {
	int len;
	char s[110];
	
	node() {
		len = 0;
		memset(s,0,sizeof(s));
	}
	
	bool getS() {
		len = strlen(s);
		
		char tmp[110];
		for(int i=0;i<len;i++)
			tmp[i] = s[len-i-1]-'0';
		for(int i=0;i<len;i++)
			s[i] = tmp[i];
		if(len <= 1 && s[0] == 0)	return false;
		//print();
		return true;
	}
	
	bool operator < (const node &t) const {
		if(len > t.len)	return false;
		else if(len < t.len) return true;
		else {
			for(int i=len-1;i>=0;i--) {
				if(s[i] > t.s[i])
					return false;
				else if(s[i] < t.s[i])
					return true;
			}
			return true;
		}
	}
	
	node operator + (const node &t) const {
		node tmp;
		for(int i=0;i<len;i++)
			tmp.s[i] = s[i]+t.s[i];
		for(int i=0;i<len+5;i++)
			if(tmp.s[i] >= 10) {
				tmp.s[i+1] += tmp.s[i]/10;
				tmp.s[i] %= 10;
			}
		for(tmp.len = len+5;tmp.len > 0 && tmp.s[tmp.len-1] == 0;tmp.len--);
		return tmp;
	}
	
	void print() {
		for(int i=len-1;i>=0;i--)
			printf("%d",s[i]);
		puts("");
	}
	
} fib[510];

int main() {

	node t,g;
	fib[0].s[0] = fib[0].len = fib[1].s[0] = fib[1].len = 1;
	for(int i=2;i<=500;i++)
		fib[i] = fib[i-1]+fib[i-2];	
	//char t[110],g[110];
		
	while(scanf("%s %s",t.s,g.s) != EOF) {
		bool a = t.getS();
		bool b = g.getS();
		if( a == 0 && b == 0 )	break;
		int count = 0;
		for(int i=1;i<=500;i++)
			if(t < fib[i] && fib[i] < g)
				count++;
		printf("%d\n",count);
	}

	return 0;
}
