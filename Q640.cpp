#include <stdio.h>

bool d[1000010];

int gen(int num) {
	int sum = num;
	while(num > 0) {
		sum += num%10;
		num /= 10;
	}
	return sum;
}

int main() {
	
	for(int i=1;i<=1000000;i++) {
		if(d[i] == false)	printf("%d\n",i);
		d[gen(i)] = true;
	}
	
	return 0;
}
