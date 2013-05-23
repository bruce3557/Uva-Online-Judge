#include <stdio.h>
#include <string.h>

struct node {
	int len;
	int s[810];
	
	node() {
		len = 0;
		memset(s,0,sizeof(s));
	}
	
	node operator + (const node &t) {
		node tmp;
		int i,max;
		max = len > t.len ? len:t.len;
		for(i=0;i<max;i++)
			tmp.s[i] = s[i]+t.s[i];
		for(i=0;i<max+5;i++)
			if(tmp.s[i] >= 10) {
				tmp.s[i+1] += tmp.s[i]/10;
				tmp.s[i] %= 10;
			}
		for(i=max+5;i>0 && tmp.s[i-1] == 0;i--);
		if(i == 0)	tmp.len = 1;
		else		tmp.len = i;
		return tmp;
	}
	
	node operator * (int t) {
		node tmp;
		int i;
		for(i=0;i<len;i++)
			tmp.s[i] = s[i]*t;
		for(i=0;i<len+5;i++)
			if(tmp.s[i] >= 10) {
				tmp.s[i+1] += tmp.s[i]/10;
				tmp.s[i] %= 10;
			}
		for(i=len+5;i>0 && tmp.s[i-1] == 0;i--);
		if(i == 0)	tmp.len = 1;
		else		tmp.len = i;
		return tmp;
	}
	
	node operator * (const node &t) {
		node tmp;
		int i,j,max = len+t.len;
		for(i=0;i<len;i++)
			for(j=0;j<t.len;j++)
				tmp.s[i+j] += s[i]*t.s[j];
		for(i=0;i<max+5;i++)
			if(tmp.s[i] >= 10) {
				tmp.s[i+1] += tmp.s[i]/10;
				tmp.s[i] %= 10;
			}
		for(i=max+5;i>0 && tmp.s[i-1] == 0;i--);
		if(i == 0)	tmp.len = 1;
		else		tmp.len = i;
		return tmp;
	}
	
	void print() {
		int i;
		//printf("%d\n",len);
		for(i=len-1;i>=0;i--)
			printf("%d",s[i]);
		puts("");
	}
	
}sta[310],cata[310],ans[310];

int main() {
	int i,j;
	
	sta[0].len = sta[0].s[0] = 1;
	sta[1].len = sta[1].s[0] = 1;
	for(i=2;i<=300;i++)
		sta[i] = sta[i-1]*i;
	
	cata[0].len = cata[0].s[0] = 1;
	cata[1].len = cata[1].s[0] = 1;
	for(i=2;i<=300;i++)
		for(j=0;j<i;j++)
			cata[i] = cata[i]+(cata[j]*cata[i-1-j]);
	
	for(i=1;i<=300;i++)
		ans[i] = cata[i]*sta[i];	
	
	int n;
	while(1) {
		scanf("%d",&n);
		if(n == 0)	break;
		ans[n].print();
	}
	
	return 0;
}
