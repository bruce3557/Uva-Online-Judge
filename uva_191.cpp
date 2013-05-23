#include <stdio.h>
#include <string.h>
#include <math.h>

double xst,yst,xed,yed;
double left,right,down,up;

double ABS(double a) {
	return a > 0 ? a : -a;
}

double Max(double a,double b) {
	return a > b ? a : b;
}

double Min(double a,double b) {
	return a < b ? a : b;
}

bool Intersect() {
	double XL = Min(xst,xed),YL = Min(yst,yed), XR = Max(xst,xed), YR = Max(yst,yed);
	//not intersect
	if(XL > right || XR < left || YL > up || YR < down)	return false;
	//in rectangle
	if(XL > left && XR < right && YL > down && YR < up)	return true;
	//one end in rectangle
	if( (xst >= left && xst <= right && yst >= down && yst <= up) || (xed >= left && xed <= right && yed >= down && yed <= up) )	return true;
	double ux,uy,dist;
	dist = sqrt((xed-xst)*(xed-xst)+(yed-yst)*(yed-yst));
	ux = (xed-xst)/dist;
	uy = (yed-yst)/dist;
	double t1,t2,t3,t4;
	t1 = (left-xst)*dist/(xed-xst);
	t2 = (right-xst)*dist/(xed-xst);
	t3 = (down-yst)*dist/(yed-yst);
	t4 = (up-yst)*dist/(yed-yst);
	/*printf("%.2lf\n",dist);
	printf("%.2lf %.2lf\n",t1,t2);
	printf("%.2lf %.2lf\n",t3,t4);*/
	t1 = t1 >= 0 ? t1 : 0;
	t3 = t3 >= 0 ? t3 : 0;
	if(t1 > t4 || t3 > t2)	return false;
	double T1,T2;
	T1 = Max(t1,t3);
	T2 = Min(t2,t4);
	//if(
	//if(T1 < T2)	return false;
	//if( (xst+ux*T1 < left) ||  (xst+ux*T2 > right) || (yst+uy*T1 < down) || (yst+uy*T2 < up) )	return false;
	return true;
}

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&xst,&yst,&xed,&yed,&left,&down,&right,&up);
		bool answer = Intersect();
		if(answer == false)	puts("F");
		else				puts("T");
	}

	return 0;
}
