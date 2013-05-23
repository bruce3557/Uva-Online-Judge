/*
 *  uva_11703.cpp
 *  
 *
 *  Created by Bruce Kuo on 2011/10/6.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int n;
int s[1000010];

inline void Build() {
	s[0] = 1;
	for(int i=1;i<=1000000;++i) {
		int pj = i-(double)sqrt(i);
		int pe = log(i);
		int pw = i*sin(i)*sin(i);
		s[i] = ((s[pj]+s[pe])%1000000+s[pw])%1000000;
		//printf("%d\n",s[i]);
	}
}

int main() {
	Build();
	while( scanf("%d",&n) && n != -1 )
		printf("%d\n",s[n]);
	return 0;
}
