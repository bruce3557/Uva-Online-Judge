/*
 *  uva_11413.cpp
 *  
 *
 *  Created by Bruce Kuo on 2011/10/6.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

int s[1010],n,m;
long long con[1010],sum,average;
bool cut[1010];

bool test(int num) {
	int len,i,j;
	
	i = n, len = 0;
	while(i > 0) {
		for(j=i-1;j>=0;j--)
			if(con[i]-con[j] > num)
				break;
		
		i = j+1;
		len++;
	}
	
	return len <= m;
}

int main() {
	
	int t,max,i,j;
	long long st,ed,mid;
		
	while( scanf("%d%d",&n,&m) != EOF) {
		con[0] = s[0] = sum = max = 0;
		memset(cut,0,sizeof(bool)*(n+1));
		
		for(i=1;i<=n;i++) {
			scanf("%d",s+i);
			con[i] = con[i-1]+s[i];
			sum += s[i];
			if(max < s[i])	max = s[i];
		}
		
		average = sum/n;
		if(average < max) average = max;
		
		st = average, ed = sum;
		while(st < ed) {
			mid = (st+ed)/2;
			if(test(mid)) {
				ed = mid;
			} else {
				st = mid+1;
			}
		}
		
		printf("%lld\n",ed); 
	}
	
	return 0;
}

