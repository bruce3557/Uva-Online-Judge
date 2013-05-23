#include <stdio.h>
#include <string.h>
#include <math.h>

double xst,yst,xed,yed;
double left,right,down,up;

bool Intersect() {
	double ux,uy,dist;
	dist = sqrt((xed-xst)*(xed-xst)+(yed-yst)*(yed-yst));
	ux = (xed-xst)/dist;
	uy = (yed-yst)/dist;
	double t1,t2,t3,t4;
	t1 = (left-xst)/ux;
	t2 = (right-xst)/ux;
	t3 = (down-yst)/uy;
	t4 = (up-yst)/uy;
	if(t1 < 0 || t3 < 0 || t2 > d || t4 > d)	return false;
	if(t2 < t3 || t4 < t1)	return false;
	return true;
}

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&xst,&yst,&xed,&yed,&left,&up,&right,&down);
		bool answer = Intersect();
		if(answer == false)	puts("F");
		else				puts("Y");
	}

	return 0;
}
