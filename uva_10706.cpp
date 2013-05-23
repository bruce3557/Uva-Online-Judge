#include <stdio.h>
#include <string.h>
#include <math.h>

long long n;
long long array[100000];

int Get(int x) {
	if(x < 10)	return 1;
	else if(x < 100)	return 2;
	else if(x < 1000)	return 3;
	else if(x < 10000)	return 4;
	else if(x < 100000)	return 5;
	else	return 6;
}

long long test(long long x) {
	long long st,ed,mid;
	st = 0, ed = (long long)sqrt(x)+100;
	while(st < ed) {
		mid = (st+ed)>>1;
		
		long long sum = array[mid];
		
		if(sum >= x)
			ed = mid;
		else
			st = mid+1;
	}
	return ed-1;
}

int main() {
	for(int i=1;i<=65536;++i)	array[i] = Get(i);
	for(int i=2;i<=65536;++i)	array[i] += array[i-1];
	for(int i=2;i<=65536;++i)	array[i] += array[i-1];

	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%lld",&n);
		long long x = test(n);
		long long next = x+1;
		long long sum = array[x];
		long long answer;
		
		for(int i=1;i<=next;++i) {
			sum += Get(i);
			if(sum >= n) {
				answer = i;
				break;
			}
		}
		
		while(sum > n) {
			answer /= 10;
			--sum;
		}
		printf("%lld\n", answer%10);
	}

	return 0;
}
