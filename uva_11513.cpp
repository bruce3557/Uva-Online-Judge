#include <stdio.h>
#include <string.h>
#include <set>
using std::set;

char start[10];
int anslen;
int ans[400010];
int stair[10];
struct node {
	char cfg[10];
	int pre, op;
} Q[400010];

struct Rec {
	int num;
	int pos;
	bool operator < (const Rec &t) const {
		return num < t.num;
	}
};

set<Rec> used;

inline bool check(const node &p) {
	for(int i=1;i<10;++i)
		if(p.cfg[i] != i)
			return false;
	return true;
}

inline int calc(char *cfg) {
	int sum = 0;
	int fac = 1;
	for(int i=1;i<=9;++i,fac*=10)
		sum += fac*cfg[i];
	return sum;
}

inline void Build() {
	stair[1] = 1;
	for(int i=2;i<=9;++i)
		stair[i] = stair[i-1]*i;
	
	for(int i=1;i<=9;++i)
		Q[0].cfg[i] = i;
	Q[0].pre = -1;
	int ff=calc(Q[0].cfg);
	used.insert((Rec){ff,0});

	int st, ed;
	st = 0, ed = 1;
	while(st < ed) {
		node tmp=Q[st];
		int face;
		node next_dice;
		
		//V3
		next_dice = tmp;
		next_dice.cfg[3] = tmp.cfg[9];
		next_dice.cfg[6] = tmp.cfg[3];
		next_dice.cfg[9] = tmp.cfg[6];
		face=calc(next_dice.cfg);
		if( used.find((Rec){face,0}) == used.end() ) {
			used.insert((Rec){face, ed});
			Q[ed] = next_dice;
			Q[ed].pre = st;
			Q[ed].op = 3;
			++ed;
		}
		
		//V2
		next_dice = tmp;
		next_dice.cfg[2] = tmp.cfg[8];
		next_dice.cfg[5] = tmp.cfg[2];
		next_dice.cfg[8] = tmp.cfg[5];
		face = calc(next_dice.cfg);
		if( used.find((Rec){face,0}) == used.end() ) {
			used.insert((Rec){face, ed});
			Q[ed] = next_dice;
			Q[ed].pre = st;
			Q[ed].op = 2;
			++ed;
		}
		
		//V1
		next_dice = tmp;
		next_dice.cfg[1] = tmp.cfg[7];
		next_dice.cfg[4] = tmp.cfg[1];
		next_dice.cfg[7] = tmp.cfg[4];
		face = calc(next_dice.cfg);
		if( used.find((Rec){face,0}) == used.end() ) {
			used.insert((Rec){face, ed});
			Q[ed] = next_dice;
			Q[ed].pre = st;
			Q[ed].op = 1;
			++ed;
		}
 		
		//H3
		next_dice =tmp;
		next_dice.cfg[7] = tmp.cfg[8];
		next_dice.cfg[8] = tmp.cfg[9];
		next_dice.cfg[9] = tmp.cfg[7];
		face=calc(next_dice.cfg);
		if( used.find((Rec){face,0}) == used.end() ) {
			used.insert((Rec){face, ed});
			Q[ed] = next_dice;
			Q[ed].pre = st;
			Q[ed].op = 6;
			++ed;
		}
		
		//H2
		next_dice = tmp;
		next_dice.cfg[4] = tmp.cfg[5];
		next_dice.cfg[5] = tmp.cfg[6];
		next_dice.cfg[6] = tmp.cfg[4];
		face=calc(next_dice.cfg);
		if( used.find((Rec){face,0}) == used.end() ) {
			used.insert((Rec){face, ed});
			Q[ed] = next_dice;
			Q[ed].pre = st;
			Q[ed].op = 5;
			++ed;
		}
		
		//H1
		next_dice = tmp;
		next_dice.cfg[1] = tmp.cfg[2];
		next_dice.cfg[2] = tmp.cfg[3];
		next_dice.cfg[3] = tmp.cfg[1];
		face=calc(next_dice.cfg);
		if( used.find((Rec){face,0}) == used.end() ) {
			used.insert((Rec){face, ed});
			Q[ed] = next_dice;
			Q[ed].pre = st;
			Q[ed].op = 4;
			++ed;
		}
		
		++st;
	}
}

int main() {
	Build();
	
	while(scanf("%d",start) && start[0]) {
		node q0;
		for(int i=1;i<9;++i)
			scanf("%d",start+i);
		
		for(int i=1;i<10;++i)
			q0.cfg[i] = start[i-1];
		int ff=calc(q0.cfg);
		set<Rec>::iterator ptr=used.find((Rec){ff,0});
		
		if( ptr == used.end() )
			puts("Not solvable");
		else {
			int back=ptr->pos;
			for(anslen=0;Q[back].pre != -1;ans[anslen++] = back, back = Q[back].pre);

			printf("%d ",anslen);
			for(int i=0;i<anslen;++i) {
				int tp = Q[ans[i]].op;
				if(tp == 1)	printf("V1");
				else if(tp == 2)	printf("V2");
				else if(tp == 3)	printf("V3");
				else if(tp == 4) 	printf("H1");
				else if(tp == 5) 	printf("H2");
				else if(tp == 6)	printf("H3");
			}
			puts("");
		}
	}
	
	return 0;
}
