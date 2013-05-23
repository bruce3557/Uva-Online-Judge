/*
 *  uva_10012.cpp
 *  
 *
 *  Created by Bruce Kuo on 2011/10/20.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int n;
int ans[10];
double minimum;
double r[10];
bool used[10];

double abs(double x) {
	return (x<0)?(-x):(x);
}

void go(int now) {
	if(now >= n) {
		double sum = 0;
		double lx, rx;
		rx = lx = 0;
		double x = r[ans[0]];
		double cx[10];
		cx[0] = r[ans[0]];
		for(int i=1;i<n;++i) {
			cx[i] = r[ans[i]];
			for(int j=0;j<i;++j) {
				double d = 2*sqrt(r[ans[i]]*r[ans[j]]);
				if(cx[i] < cx[j]+d)	cx[i] = cx[j]+d;
			}
		}
		
		for(int i=0;i<n;++i) {
			if(cx[i]+r[ans[i]] > rx)	rx = cx[i]+r[ans[i]];
			if(cx[i]-r[ans[i]] < lx)	lx = cx[i]-r[ans[i]];
		}
		sum = rx-lx;
		if(minimum > sum)	minimum = sum;
		return;
	}
	
	for(int i=0;i<n;++i) {
		if(used[i])	continue;
		ans[now] = i;
		used[i] = 1;
		go(now+1);
		used[i] = 0;
	}
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%lf",r+i);
		minimum = 1e12;
		memset(used, 0, sizeof(used));
		go(0);
		printf("%.3lf\n",minimum);
	}
	return 0;
}
