#include <stdio.h>
#include <string.h>

const double vcruise=400;
const double aopt=30;
const double gph_opt=2000;
const double gph_extra=10;
const double climb_cost=50;

int main() {

	double length;
	double tw_bt;
	double tw_up;
	double leg_fuel;
	double total_fuel;
	double wind;
	int best_alt;
	
	int t, cases=0;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		printf("Flight %d:",++cases);
		total_fuel = 0;
		while(n--) {
			scanf("%lf%lf%lf", &length, &tw_bt, &tw_up);
			double speed = 0.5*(tw_bt+tw_up)+vcruise;
			double f_time = length/speed;
			double l_fuel = 
			double min

			best_alti = (int)aopt;
			
			printf(" %d", best_alti);
		}
		printf("%.0lf\n", total_fuel);
	}

	return 0';
}
