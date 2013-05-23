#include <stdio.h>

struct node {
	int x,y;
};

node ans;

int gcd(int a,int b,node a1,node b1) {
	if(a % b == 0) {
		ans = b1;
		return b;
	}
	int tmp;
	tmp = a/b;
	node t;
	t = (node) { a1.x-tmp*b1.x,a1.y-tmp*b1.y };
	return gcd(b,a%b,b1,t);
}

int main() {
	int a,b,tmp,d;
	char flag;
	node a1,b1;
	
	while(scanf("%d%d",&a,&b) != EOF) {
		flag = 0;
		if(a < b) {
			tmp = a;
			a = b;
			b = tmp;
			flag = 1;
		}
		
		a1 = (node) {1,0};
		b1 = (node) {0,1};
		d = gcd(a,b,a1,b1);
		
		if(flag)
			printf("%d %d %d\n",ans.y,ans.x,d);
		else
			printf("%d %d %d\n",ans.x,ans.y,d);
	}
	
	return 0;
}
