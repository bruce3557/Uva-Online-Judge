#include <stdio.h>
#include <string.h>

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

//dice will have a standard model

int r,c;
int anslen;
int map[12][12];
int rotate[24][4];
char map_name[30];
char used[12][12][24];

struct Dice {
	int top, front;
} state[24];

struct node {
	int x, y, prev;
	int dice;
} Q[5010], ans[5010];

inline bool check(int x, int y) {
	return (x > 0 && x <= r && y > 0 && y <= c);
}

inline void Build() {
	state[0] = (Dice){1, 2}; state[1] = (Dice){1, 3}; state[2] = (Dice){1, 4}; state[3] = (Dice){1, 5};
	state[4] = (Dice){2, 1}; state[5] = (Dice){2, 3}; state[6] = (Dice){2, 4}; state[7] = (Dice){2, 6};
	state[8] = (Dice){3, 1}; state[9] = (Dice){3, 2}; state[10] = (Dice){3, 5}; state[11] = (Dice){3, 6};
	state[12] = (Dice){4, 1}; state[13] = (Dice){4, 2}; state[14] = (Dice){4, 5}; state[15] = (Dice){4, 6};
	state[16] = (Dice){5, 1}; state[17] = (Dice){5, 3}; state[18] = (Dice){5, 4}; state[19] = (Dice){5, 6};
	state[20] = (Dice){6, 2}; state[21] = (Dice){6, 3}; state[22] = (Dice){6, 4}; state[23] = (Dice){6, 5};
	
	rotate[0][0] = 7; rotate[0][1] = 9; rotate[0][2] = 16; rotate[0][3] = 13;
	rotate[1][0] = 11; rotate[1][1] = 17; rotate[1][2] = 12; rotate[1][3] = 5;
	rotate[2][0] = 15; rotate[2][1] = 6; rotate[2][2] = 8; rotate[2][3] = 18;
	rotate[3][0] = 19; rotate[3][1] = 14; rotate[3][2] = 4; rotate[3][3] = 10;
	
	rotate[4][0] = 3; rotate[4][1] = 12; rotate[4][2] = 20; rotate[4][3] = 8;
	rotate[5][0] = 10; rotate[5][1] = 1; rotate[5][2] = 13; rotate[5][3] = 21;
	rotate[6][0] = 14; rotate[6][1] = 22; rotate[6][2] = 9; rotate[6][3] = 2;
	rotate[7][0] = 23; rotate[7][1] = 11; rotate[7][2] = 0; rotate[7][3] = 15;
	
	rotate[8][0] = 2; rotate[8][1] = 4; rotate[8][2] = 21; rotate[8][3] = 16;
	rotate[9][0] = 6; rotate[9][1] = 20; rotate[9][2] = 17; rotate[9][3] = 0;
	rotate[10][0] = 18; rotate[10][1] = 3; rotate[10][2] = 5; rotate[10][3] = 23;
	rotate[11][0] = 22; rotate[11][1] = 19; rotate[11][2] = 1; rotate[11][3] = 7;
	
	rotate[12][0] = 1; rotate[12][1] = 16; rotate[12][2] = 22; rotate[12][3] = 4;
	rotate[13][0] = 5; rotate[13][1] = 0; rotate[13][2] = 18; rotate[13][3] = 20;
	rotate[14][0] = 17; rotate[14][1] = 23; rotate[14][2] = 6; rotate[14][3] = 3;
	rotate[15][0] = 21; rotate[15][1] = 7; rotate[15][2] = 2; rotate[15][3] = 19;
	
	rotate[16][0] = 0; rotate[16][1] = 8; rotate[16][2] = 23; rotate[16][3] = 12;
	rotate[17][0] = 9; rotate[17][1] = 21; rotate[17][2] = 14; rotate[17][3] = 1;
	rotate[18][0] = 13; rotate[18][1] = 2; rotate[18][2] = 10; rotate[18][3] = 22;
	rotate[19][0] = 20; rotate[19][1] = 15; rotate[19][2] = 3; rotate[19][3] = 11;
	
	rotate[20][0] = 4; rotate[20][1] = 13; rotate[20][2] = 19; rotate[20][3] = 9;
	rotate[21][0] = 8; rotate[21][1] = 5; rotate[21][2] = 15; rotate[21][3] = 17;
	rotate[22][0] = 12; rotate[22][1] = 18; rotate[22][2] = 11; rotate[22][3] = 6;
	rotate[23][0] = 16; rotate[23][1] = 10; rotate[23][2] = 7; rotate[23][3] = 14;
}

inline int getNextDice(int dice, int rot) {
	return rotate[dice][rot];
}

int main() {
	int x, y, up, ft;
	Build();
	
	while(scanf("%s",map_name) && strcmp(map_name,"END")) {
		puts(map_name);
		scanf("%d%d%d%d%d%d",&r,&c,&x,&y,&up,&ft);
		
		for(int i=1;i<=r;++i)
			for(int j=1;j<=c;++j)
				scanf("%d",&map[i][j]);
				
		memset(used,0,sizeof(used));
		
		//start to find solution
		int first_dice=0;
		for(;state[first_dice].top != up || state[first_dice].front != ft;++first_dice);
		node first=(node){x, y, -1, first_dice};
		int front, last;
		front = last = 0;
		Q[last++] = first;
		
		while( front < last ) {
			node t=Q[front];
			if(t.prev != -1 && t.x == x && t.y == y)	break;
			for(int i=0;i<4;++i) {
				int next_x=t.x+dx[i];	int next_y=t.y+dy[i];
				if( check(next_x, next_y) &&  (map[next_x][next_y] == -1 || map[next_x][next_y] == state[t.dice].top)) {
					int next_dice = getNextDice(t.dice, i);
					if( !used[next_x][next_y][next_dice] ) {
						used[next_x][next_y][next_dice] = 1;
						Q[last++] = (node){next_x, next_y, front, next_dice};
					}
				}
			}
			++front;
		}
		
		if(front >= last) {
			puts("  No Solution Possible");
		} else {
			int ptr=front;
			anslen = 0;
			while(Q[ptr].prev != -1) {
				ans[anslen++] = Q[ptr];
				ptr = Q[ptr].prev;
			}
			ans[anslen++] = Q[ptr];
			printf("  (%d,%d)", Q[ptr].x, Q[ptr].y);
			for(int i=anslen-2;i>=0;--i) {
				printf(",");
				if( ((anslen-i)%9) == 1 )	printf("\n  ");
				printf("(%d,%d)", ans[i].x, ans[i].y);
			}
			puts("");
		}
	}

	return 0;
}
