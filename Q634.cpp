#include <stdio.h>
#include <string.h>

int n;
struct node {
	int x,y;
	
	void getNode() { scanf("%d%d",&x,&y); }
} polygon[1010],test;

bool Scr(int a,int b) {
	return ((polygon[a].y <= test.y && test.y <= polygon[b].y) || (polygon[b].y <= test.y && test.y <= polygon[a].y));
}

int main() {

	while(scanf("%d",&n) && n) {
		for(int i=0;i<n;i++)
			polygon[i].getNode();
		polygon[n] = polygon[0];
		test.getNode();
		
		int counter = 0;
		for(int i=1;i<=n;i++)
			if(polygon[i].x == polygon[i-1].x && polygon[i].x < test.x && Scr(i,i-1))
				counter++;
		
		if(counter & 1)	puts("T");
		else			puts("F");
	}

	return 0;
}
