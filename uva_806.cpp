#include <stdio.h>
#include <string.h>
#include <algorithm>

int n;
int len;
char map[70][70];
int list[5000];
int len_s;
int stack[5000];

void Check(int up_x, int up_y, int bt_x, int bt_y) {
	int mid_x = (up_x+bt_x)/2;
	int mid_y = (up_y+bt_y)/2;

	int blocks=0;
	
	//all black
	for(int i=up_x;i<bt_x;++i)
		for(int j=up_y;j<bt_y;++j)
			if(map[i][j])
				++blocks;
	
	if(blocks == 0 || blocks == (bt_x-up_x)*(bt_y-up_y)) {
		if(!blocks)	return;
		int num = 1;
		int sum = 0;
		for(int i=0;i<len_s;++i,num*=5)
			sum += stack[i]*num;
		list[len++] = sum;
		return;
	}
	//left up
	stack[len_s++] = 1;
	Check(up_x, up_y, mid_x, mid_y);
	--len_s;
	
	//right up
	stack[len_s++] = 2;
	Check(up_x, mid_y, mid_x, bt_y);
	--len_s;
	
	//left down
	stack[len_s++] = 3;
	Check(mid_x, up_y, bt_x, mid_y);
	--len_s;
	
	stack[len_s++] = 4;
	Check(mid_x, mid_y, bt_x, bt_y);
	--len_s;
}

void fill(int up_x, int up_y, int bt_x, int bt_y, int count) {
	if(count >= len_s) {
		for(int i=up_x;i<bt_x;++i)
			for(int j=up_y;j<bt_y;++j)
				map[i][j] = '*';
		return;
	}
	
	int mid_x = (up_x+bt_x)/2;
	int mid_y = (up_y+bt_y)/2;
	if(stack[count] == 1) {
		fill(up_x, up_y, mid_x, mid_y, count+1);
	} else if(stack[count] == 2) {
		fill(up_x, mid_y, mid_x, bt_y, count+1);
	} else if(stack[count] == 3) {
		fill(mid_x, up_y, bt_x, mid_y, count+1);
	} else {
		fill(mid_x, mid_y, bt_x, bt_y, count+1);
	}
}


int main() {
	int cases=0;
	
	while(scanf("%d",&n) && n) {
		if(cases)	puts("");
		printf("Image %d\n", ++cases);
		if(n < 0) {
			n = -n;
			for(int i=0;i<n;++i)
				for(int j=0;j<n;++j)
					map[i][j] = '.';
			for(len = 0;scanf("%d",&list[len]) && list[len] != -1;++len);
			
			if( len ) {
				if(list[0] == 0) {
					for(int i=0;i<n;++i)
						for(int j=0;j<n;++j)
							map[i][j] = '*';
				} else {
					for(int i=0;i<len;++i) {
						int tmp = list[i];
						len_s = 0;
						while(tmp > 0) {
							stack[len_s] = tmp%5;
							tmp /= 5;
							++len_s;
						}
						fill(0, 0, n, n, 0);
					}
				}
			}
			for(int i=0;i<n;++i, puts(""))
				for(int j=0;j<n;++j)
					printf("%c", map[i][j]);
		} else {
			for(int i=0;i<n;++i)
				scanf("%s", map[i]);
				
			for(int i=0;i<n;++i)
				for(int j=0;j<n;++j)
					map[i][j] -= '0';
			
			len = len_s = 0;
			Check(0, 0, n, n);
			if(len) {
				std::sort(list, list+len);
				printf("%d",list[0]);
				for(int i=1;i<len;++i) {
					if(i%12 == 0)
						printf("\n%d", list[i]);
					else
						printf(" %d",list[i]);
				}
				puts("");
			}
			
			printf("Total number of black nodes = %d\n", len);
		}
	}
	
	return 0;
}
