/*
 *  uva_10977.cpp
 *  
 *
 *  Created by Christina on 2011/8/5.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

struct node {
	int len;
	int s[5010];
	
	node() {
		len = 0;
		memset(s, 0, sizeof(s));
	}
	
	node operator + (const node &t) const {
		node res;
		res.len = (len > t.len) ? len : t.len;
		for(int i=0;i<res.len;++i)
			res.s[i] = s[i]+t.s[i];
		for(int i=0;i<res.len+5;++i)
			if(res.s[i] >= 10) {
				res.s[i+1] += res.s[i]/10;
				res.s[i]%=10;
			}
		res.len = res.len+5;
		for(;res.len > 0 && res.s[res.len-1] == 0;--res.len);
		return res;
	}
			
	node operator * (const node &t) const {
		node res;
		res.len = (len+t.len);
		for(int i=0;i<len;++i)
			for(int j=0;j<t.len;++j)
				res.s[i+j] += s[i]*t.s[j];
		for(int i=0;i<res.len+5;++i)
			if(res.s[i] >= 10) {
				res.s[i+1] += res.s[i]/10;
				res.s[i] %= 10;
			}
		res.len += 10;
		for(;res.len > 0 && res.s[res.len-1];--res.len);
		return res;
	}
	
	void print() {
		for(int i=len-1;i>=0;--i)
			printf("%d",s[i]);
		puts("");
	}
} seq[1010];

int main() {
	int n;
	seq[0].len = 1;
	seq[0].s[0] = 1;
	
	for(int i=1;i<=1000;++i)
		for(int j=1;j<5;++j) {
			//printf("%d %d\n",i,j);
			if(j != 4 && i < j) continue;
			if(j == 4)	seq[i] = seq[i]+seq[i-1];
			else		seq[i] = seq[i]+seq[i-j];
		}
	
	while( scanf("%d",&n) != EOF )
		seq[n].print();
	
	return 0;
}
