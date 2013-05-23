#include <stdio.h>
#include <string.h>
#define MAX 2147483644

int n, m;
int len;
int map[600][600];
struct node {
	int x1, y1;	//upper left
	int x2, y2;	//bottom right
	int maxi, mini;
	
	node *next[4]; // left_up, right_up, left_bt, right_bt
	
	node() {
		maxi = 0;
		mini = MAX;
		for(int i=0;i<4;++i)	next[i] = NULL;
	}
};

inline int Maximum(int a, int b) {
	return (a > b) ? a : b;
}

inline int Minimum(int a, int b) {
	return (a < b) ? a : b;
}

node *Build(node *ptr, int x1, int y1, int x2, int y2) {
	//printf("%d %d %d %d\n",x1, y1, x2 ,y2);
	if(x1 >= x2 && y1 >= y2) {
		node *tmp = new node();
		tmp->x1 = tmp->x2 = x1;
		tmp->y1 = tmp->y2 = y1;
		tmp->maxi = map[x2][y2];
		tmp->mini = map[x2][y2];
		return tmp;
	}
	
	int midx = (x1+x2)/2;
	int midy = (y1+y2)/2;
	node *tmp = new node();
	tmp->x1 = x1; tmp->x2 = x2; tmp->y1 = y1; tmp->y2 = y2;
	tmp->next[0] = Build(tmp->next[0], x1, y1, midx, midy);
	tmp->next[1] = Build(tmp->next[1], x1, midy+1, midx, y2);
	tmp->next[2] = Build(tmp->next[2], midx+1, y1, x2, midy);
	tmp->next[3] = Build(tmp->next[3], midx+1, midy+1, x2, y2);
	for(int i=0;i<4;++i) 
		if(1 <= tmp->next[i]->x1 && n >= tmp->next[i]->x2 && 1 <= tmp->next[i]->y1 && m >= tmp->next[i]->y2) {
			tmp->maxi = Maximum(tmp->maxi, tmp->next[i]->maxi);
			tmp->mini = Minimum(tmp->mini, tmp->next[i]->mini);
		}
	
	return tmp;
}

void Query(node *ptr, int x1, int y1, int x2, int y2, int &Max, int &Min) {
	if(ptr == NULL)	return;
	if(ptr->x2 < 1 || ptr->x1 > n || ptr->y1 > m || ptr->y2 < 1)	return;
	if(ptr->x1 == x1 && ptr->x2 == x2 && ptr->y1 == y1 && ptr->y2 == y2) {
		if(Max < ptr->maxi)	Max = ptr->maxi;
		if(Min > ptr->mini)	Min = ptr->mini;
		return ;
	}
	int midx = (ptr->x1+ptr->x2)/2;
	int midy = (ptr->y1+ptr->y2)/2;
	
	if(ptr->x1 <= x1 && ptr->y1 <= y1 && midx >= x2 && midy >= y2) {//in left up
		Query(ptr->next[0], x1, y1, x2, y2, Max, Min);
	} else if(midy < y1 && ptr->y2 >= y2 && midx >= x2 && ptr->x1 <= x1) {//in right up
		Query(ptr->next[1], x1, y1, x2, y2, Max, Min);
	} else if(midy >= y2 && y1 >= ptr->y1 && x2 <= ptr->x2 && midx < x1) {//in left down
		Query(ptr->next[2], x1, y1, x2, y2, Max, Min);
	} else if(midx < x1 && midy < y1 && ptr->x2 >= x2 && ptr->y2 >= y2) {//in right down
		Query(ptr->next[3], x1, y1, x2, y2, Max, Min);
	} else if(midx < x2 && x1 <= midx && midy >= y2 && ptr->y1 <= y1) {	//left side
		Query(ptr->next[0], x1, y1, midx, y2, Max, Min);
		Query(ptr->next[2], midx+1, y1, x2, y2, Max, Min);
	} else if(midx < x2 && x1 <= midx && midy < y1 && ptr->y2 >= y2) {	//right side
		Query(ptr->next[1], x1, y1, midx, y2, Max, Min);
		Query(ptr->next[3], midx+1, y1, x2, y2, Max, Min);
	} else if(x1 >= ptr->x1 && x2 <= midx && y1 <= midy && y2 > midy) {	//up side
		Query(ptr->next[0], x1, y1, x2, midy, Max, Min);
		Query(ptr->next[1], x1, midy+1, x2, y2, Max, Min);
	} else if(midx < x1 && ptr->x2 >= x2 && y1 <= midy && y2 > midy) {//down side
		Query(ptr->next[2], x1, y1, x2, midy, Max, Min);
		Query(ptr->next[3], x1, midy+1, x2, y2, Max, Min);
	} else {
		Query(ptr->next[0], x1, y1, midx, midy, Max, Min);
		Query(ptr->next[1], x1, midy+1, midx, y2, Max, Min);
		Query(ptr->next[2], midx+1, y1, x2, midy, Max, Min);
		Query(ptr->next[3], midx+1, midy+1, x2, y2, Max, Min);
	}
}

void Change(node *ptr, int x, int y, int value) {
	if(ptr->x1 == x && ptr->x2 == x && ptr->y1 == y && ptr->y2 == y) {
		map[x][y] = value;
		ptr->maxi = value;
		ptr->mini = value;
		return;
	}
	for(int i=0;i<4;++i)
		if(ptr->next[i]->x1 <= x && ptr->next[i]->x2 >= x && ptr->next[i]->y1 <= y && ptr->next[i]->y2 >= y)
			Change(ptr->next[i], x, y, value);
	ptr->maxi = 0;
	ptr->mini = MAX;
	for(int i=0;i<4;++i) {
		if(ptr->next[i]->maxi > ptr->maxi)
			ptr->maxi = ptr->next[i]->maxi;
		if(ptr->next[i]->mini < ptr->mini)
			ptr->mini = ptr->next[i]->mini;
	}
}

int main() {
	
	scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				scanf("%d",&map[i][j]);
		int bigger=(n>m)?n:m;
		for(len=1;len<bigger;len*=2);
		node *root = Build(root, 1, 1, len, len);		
		
		int Q;
		scanf("%d", &Q);
		while(Q--) {
			char op[5];
			scanf("%s",op);
			if(op[0] == 'q') {
				int x1,y1,x2,y2;
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				if(n == 0 || m == 0) {
					puts("0 0");
					continue;
				}
				int Max, Min;
				Max = 0; Min = MAX;
				Query(root, x1, y1, x2, y2, Max, Min);
				printf("%d %d\n", Max, Min);
			} else {
				int x, y, c;
				scanf("%d%d%d", &x, &y, &c);
				Change(root, x, y, c);
			}
		}
		
	return 0;
}
