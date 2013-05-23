#include <stdio.h>

struct node {
	int state,first,last;
	int s[1050];
} hand[5],deck[5][10],record[10];

int step[5],state[5],ptr[5],cstep;

int check(int num) {
	if(num == 1) {
		if(hand[1].last < hand[1].first)	return 0;
		if(hand[1].last-hand[1].first >= 51)	return 1;
		int i,j,k;
		for(i=0;i<7;i++) 
			if(record[i].last-record[i].first != deck[1][i].last-deck[1][i].first)
				return -1;
		if(record[7].last-record[7].first != hand[1].last-hand[1].first)	return -1;
		for(i=0;i<7;i++)
			for(j=deck[1][i].first,k=record[i].first;j<=deck[1][i].last;j++,k++)
				if(deck[1][i].s[j] != record[i].s[k])
					return -1;
		for(j=hand[1].first,k=record[7].first;j<=hand[1].last;j++,k++)
			if(hand[1].s[j] != record[7].s[k])
				return -1;
		return 2;
	} else if(num == 2) {
		int i,j,k;
		for(i=0;i<7;i++)
			if(deck[2][i].last-deck[2][i].first != deck[3][i].last-deck[3][i].first)
				return 0;
		if(hand[2].last-hand[2].first != hand[3].last-hand[3].first)	return 0;
		for(i=0;i<7;i++)
			for(j=deck[2][i].first+1,k=deck[3][i].first+1;j<=deck[2][i].last;j++,k++)
				if(deck[2][i].s[j] != deck[3][i].s[k])
					return 0;
		for(j=hand[2].first,k=hand[3].first;j<=hand[2].last;j++,k++)
			if(hand[2].s[j] != hand[3].s[k])
				return 0;
		return 1;
	}	
}

void simulation(int num) {
	int now = deck[num][ptr[num]].last+1;
	deck[num][ptr[num]].last++;
	deck[num][ptr[num]].s[now] = hand[num].s[hand[num].first];
	hand[num].first++;
	
	int tmp,f,r;
	while(1) {
		if(deck[num][ptr[num]].last-deck[num][ptr[num]].first >= 3) {
			f = deck[num][ptr[num]].first+1;
			r = deck[num][ptr[num]].last;
			tmp = deck[num][ptr[num]].s[f]+deck[num][ptr[num]].s[f+1]+deck[num][ptr[num]].s[r];
			if(tmp == 10 || tmp == 20 || tmp == 30) {
				hand[num].s[hand[num].last+1] = deck[num][ptr[num]].s[f];
				hand[num].s[hand[num].last+2] = deck[num][ptr[num]].s[f+1];
				hand[num].s[hand[num].last+3] = deck[num][ptr[num]].s[r];
				hand[num].last += 3;
				deck[num][ptr[num]].first += 2;
				deck[num][ptr[num]].last--;
				if(deck[num][ptr[num]].last <= deck[num][ptr[num]].first) {
					deck[num][ptr[num]].state = -1;
					break;
				}
				continue;
			}
			tmp = deck[num][ptr[num]].s[f]+deck[num][ptr[num]].s[r-1]+deck[num][ptr[num]].s[r];
			if(tmp == 10 || tmp == 20 || tmp == 30) {
				hand[num].s[hand[num].last+1] = deck[num][ptr[num]].s[f];
				hand[num].s[hand[num].last+2] = deck[num][ptr[num]].s[r-1];
				hand[num].s[hand[num].last+3] = deck[num][ptr[num]].s[r];
				hand[num].last += 3;
				deck[num][ptr[num]].first++;
				deck[num][ptr[num]].last -= 2;
				if(deck[num][ptr[num]].last <= deck[num][ptr[num]].first) {
					deck[num][ptr[num]].state = -1;
					break;
				}
				continue;
			}
			tmp = deck[num][ptr[num]].s[r-2]+deck[num][ptr[num]].s[r-1]+deck[num][ptr[num]].s[r];
			if(tmp == 10 || tmp == 20 || tmp == 30) {
				hand[num].s[hand[num].last+1] = deck[num][ptr[num]].s[r-2];
				hand[num].s[hand[num].last+2] = deck[num][ptr[num]].s[r-1];
				hand[num].s[hand[num].last+3] = deck[num][ptr[num]].s[r];
				hand[num].last += 3;
				deck[num][ptr[num]].last -= 3;
				if(deck[num][ptr[num]].last <= deck[num][ptr[num]].first) {
					deck[num][ptr[num]].state = -1;
					break;
				}
				continue;
			}
		}
		break;
	}
}

int main() {
	int i;
	while(scanf("%d",&hand[1].s[0]) && hand[1].s[0]) {
		for(i=1;i<52;i++)
			scanf("%d",&hand[1].s[i]);
		hand[1].first = 0,hand[1].last = 51;
		hand[2] = hand[3] = hand[1];
		
		state[2] = step[1] = step[2] = step[3] = ptr[1] = ptr[2] = ptr[3] = 0;
		for(i=0;i<=7;i++) {
			record[i].first = record[i].last = 0;
			deck[1][i].state = deck[2][i].state = deck[3][i].state = 0;
			deck[1][i].first = deck[2][i].first = deck[3][i].first = 0;
			deck[1][i].last = deck[2][i].last = deck[3][i].last = 0;
		}
		for(i=0;i<7;i++)
			record[i] = deck[1][i];
		record[7] = hand[1];
		
		state[1] = -1;
		cstep = 1;
		while(1) {
			step[1]++;
			simulation(1);
			if(step[1] > 14) {
				state[1] = check(1);
				if(state[1] >= 0)	break;
			}
			ptr[1]++;
			if(ptr[1] == 7)	ptr[1] = 0;
			while(deck[1][ptr[1]].state < 0) {
				ptr[1]++;
				if(ptr[1] >= 7)	ptr[1] = 0;
			}
			if(step[1] == cstep) {
				for(i=0;i<7;i++)
					record[i] = deck[1][i];
				record[7] = hand[1];
				cstep *= 2;
			}
		}
		
		if(state[1] == 0) {
			printf("Loss: %d\n",step[1]);
		} else if(state[1] == 1) {
			printf("Win : %d\n",step[1]);
		} else {
			int period = step[1]-(cstep/2);
			for(i=0;i<period;i++) {
				step[2]++;
				simulation(2);
				ptr[2]++;
				if(ptr[2] >= 7)	ptr[2] = 0;
				while(deck[2][ptr[2]].state < 0) {
					ptr[2]++;
					if(ptr[2] == 7)	ptr[2] = 0;
				}
			}
			
			while(1) {
				step[2]++;
				step[3]++;
				simulation(2);
				simulation(3);
				if(step[3] > 14) {
					state[2] = check(2);
					if(state[2])	break;
				}
				ptr[2]++;
				if(ptr[2] >= 7)	ptr[2] = 0;
				while(deck[2][ptr[2]].state < 0) {
					ptr[2]++;
					if(ptr[2] == 7)	ptr[2] = 0;
				}
				ptr[3]++;
				if(ptr[3] >= 7)	ptr[3] = 0;
				while(deck[3][ptr[3]].state < 0) {
					ptr[3]++;
					if(ptr[3] == 7)	ptr[3] = 0;
				}
			}
			printf("Draw: %d\n",step[2]);
		}
	}
	
	return 0;
}
