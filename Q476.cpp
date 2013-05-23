#include <stdio.h>
#include <math.h>

struct node{
	double x1,x2,x3,y1,y2,y3;
} rect[15];

double abs(double x) {
	if(x < 0)	return -x;
	return x;
}

int main() {
	char c,flag;
	int i,n,t=0;
	int s[15];
	double x,y,a,b,cc,d;
	
	n = 1;
	while(scanf("%c",&c) && c != '*') {
		if(c == 'r') {
			scanf("%lf%lf%lf%lf%*c",&rect[n].x1,&rect[n].y1,&rect[n].x2,&rect[n].y2);
			s[n] = 0;
		} else if(c == 'c') {
			scanf("%lf%lf%lf%*c",&rect[n].x1,&rect[n].x2,&rect[n].y1);
			s[n] = 1;
		} else if(c == 't') {
			scanf("%lf%lf%lf%lf%lf%lf%*c",&rect[n].x1,&rect[n].y1,&rect[n].x2,&rect[n].y2,&rect[n].x3,&rect[n].y3);
			s[n] = 2;
		}
		n++;
	}
	
	while(scanf("%lf%lf",&x,&y)) {
		if(x == 9999.9 && y == 9999.9)	break;
		flag = 0;
		++t;
		for(i=1;i<n;i++)
			if(s[i] == 0) {
				if(x > rect[i].x1 && x < rect[i].x2 && y < rect[i].y1 && y > rect[i].y2) {
					flag = 1;
					printf("Point %d is contained in figure %d\n",t,i);
				}
			} else if(s[i] == 1) {
				if(sqrt((rect[i].x1-x)*(rect[i].x1-x)+(rect[i].x2-y)*(rect[i].x2-y)) < rect[i].y1) {
					flag = 1;
					printf("Point %d is contained in figure %d\n",t,i);
				}
			} else if(s[i] == 2) {
				d = abs(rect[i].x2*rect[i].y3+rect[i].x3*rect[i].y1+rect[i].x1*rect[i].y2-rect[i].x3*rect[i].y2-rect[i].x1*rect[i].y3-rect[i].x2*rect[i].y1);
				a = abs(rect[i].x1*rect[i].y2+rect[i].x2*y+x*rect[i].y1-rect[i].x2*rect[i].y1-x*rect[i].y2-rect[i].x1*y);
				b = abs(rect[i].x2*rect[i].y3+rect[i].x3*y+x*rect[i].y2-rect[i].x3*rect[i].y2-x*rect[i].y3-rect[i].x2*y);
				cc =abs(rect[i].x3*rect[i].y1+rect[i].x1*y+x*rect[i].y3-rect[i].x1*rect[i].y3-x*rect[i].y1-rect[i].x3*y);
				if(abs(a) && abs(b) && abs(cc) && abs(a+b+cc-d) <= 1e-6) {
					flag = 1;
					printf("Point %d is contained in figure %d\n",t,i);
				}
			}
		if(flag == 0)
			printf("Point %d is not contained in any figure\n",t);
	}
	
	return 0;
}
