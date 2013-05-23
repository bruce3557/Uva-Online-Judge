#include <stdio.h>
#include <string.h>

const double area = 100;

int n,m;
int counter=0;
int map[32][32];
double water;
double altitude;
double percent;
char submerged[32][32];

struct node {
	int x,y;
} loc[950];

int main() {
	int c=0;
	
	while(scanf("%d%d",&n,&m) && n+m) {
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				scanf("%d",&map[i][j]);
		scanf("%lf",&water);
				
		memset(submerged, 0, sizeof(submerged));
		while(water > 0) {
			int minimum = 999999999;
			for(int i=0;i<n;++i)
				for(int j=0;j<m;++j) {
					if(minimum > map[i][j]) {
						minimum = map[i][j];
						loc[0] = (node){i,j};
						counter = 1;
					} else if(minimum == map[i][j]) {
						loc[counter++] = (node){i,j};
					}
				}
			
			int next_min = 999999999;
			for(int i=0;i<n;++i)
				for(int j=0;j<m;++j)
					if(map[i][j] > minimum && next_min > map[i][j])
						next_min = map[i][j];

			int diff = next_min - minimum;
			if((double)diff*area*counter <= water) {
				water -= (double)diff*area*counter;
				for(int i=0;i<counter;++i) {
					map[loc[i].x][loc[i].y] = (int)next_min;
					submerged[loc[i].x][loc[i].y] = 1;
				}
			} else {
				//Area*altitude = water
				double Area = counter*area;
				altitude = water/Area + minimum;
				for(int i=0;i<counter;++i)
					submerged[loc[i].x][loc[i].y] = 1;
				water = -1;
			}
		}
		
		int count=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				if(submerged[i][j])
					++count;
		
		percent = (double)count/(n*m);
		printf("Region %d\n", ++c);
		printf("Water level is %.2lf meters.\n", altitude);
		printf("%.2lf percent of the region is under water.\n\n", percent*100);
	}

	return 0;
}
