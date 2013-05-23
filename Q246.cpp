#include <stdio.h>

struct node {
	int first,last,state;
	int s[2000];
} deck[10],hand,record[10],deckk[10],deckkk[10],handd,handdd;

int state,step,cstep,ptr;
int ptrr,stepp,statee;
int ptrrr,steppp;

int check() {
	if(hand.last-hand.first == 51)	return 1;
	if(hand.first == hand.last)	return 0;	
	
	int i,j,k;
	for(i=0;i<7;i++)
		if((record[i].last-record[i].first) != (deck[i].last-deck[i].first))
			return -1;
	for(i=0;i<7;i++)
		for(j=deck[i].first+1,k=record[i].first+1;j<=deck[i].last;j++,k++)
			if(deck[i].s[j] != record[i].s[k])
				return -1;
	if(hand.last-hand.first == record[7].last-record[7].first) {
		for(j=hand.first,k=record[7].first;j<=hand.last;j++,k++)
			if(hand.s[j] != record[7].s[k])
				return -1;
		return 2;
	}
	return -1;
}

int check2() {	
	int i,j,k;
	for(i=0;i<7;i++)
		if(deckk[i].last-deckk[i].first != deckkk[i].last-deckkk[i].first)
			return 0;
	for(i=0;i<7;i++)
		for(j=deckk[i].first+1,k=deckkk[i].first+1;j<=deckk[i].last;j++,k++)
			if(deckk[i].s[j] != deckkk[i].s[k])
				return 0;
	if(handd.last-handd.first == handdd.last-handdd.first) {
		for(j=handd.first,k=handdd.first;j<=handd.last;j++,k++)
			if(handd.s[j] != handdd.s[k])
				return 0;
		return 1;
	}
	return 0;
}

void simulate() {
	int now = deck[ptr].last+1;
	deck[ptr].last++;
	deck[ptr].s[now] = hand.s[hand.first];
	hand.first++;
	step++;
	
	int f,r,tmp,i;
	while(1) {
		if(deck[ptr].last-deck[ptr].first >= 3) {
			f = deck[ptr].first+1;
			r = deck[ptr].last;
			tmp = deck[ptr].s[f]+deck[ptr].s[f+1]+deck[ptr].s[r];
			if(tmp == 10 || tmp == 20 || tmp == 30) {
				hand.s[hand.last+1] = deck[ptr].s[f];
				hand.s[hand.last+2] = deck[ptr].s[f+1];
				hand.s[hand.last+3] = deck[ptr].s[r];	
				hand.last += 3;
				
				deck[ptr].first += 2;
				deck[ptr].last--;
				if(deck[ptr].first >= deck[ptr].last) {
					deck[ptr].state = -1;
					break;
				}
				continue;
			}
			tmp = deck[ptr].s[f]+deck[ptr].s[r-1]+deck[ptr].s[r];
			if(tmp == 10 || tmp == 20 || tmp == 30) {
				hand.s[hand.last+1] = deck[ptr].s[f];
				hand.s[hand.last+2] = deck[ptr].s[r-1];
				hand.s[hand.last+3] = deck[ptr].s[r];
				hand.last += 3;
				
				deck[ptr].last -= 2;
				deck[ptr].first++;
				if(deck[ptr].first >= deck[ptr].last) {
					deck[ptr].state = -1;
					break;
				}
				continue;
			}
			tmp = deck[ptr].s[r-2]+deck[ptr].s[r-1]+deck[ptr].s[r];
			if(tmp == 10 || tmp == 20 || tmp == 30) {
				hand.last++;
				hand.s[hand.last] = deck[ptr].s[r-2];
				hand.last++;
				hand.s[hand.last] = deck[ptr].s[r-1];
				hand.last++;
				hand.s[hand.last] = deck[ptr].s[r];
				
				deck[ptr].last -= 3;
				if(deck[ptr].first >= deck[ptr].last) {
					deck[ptr].state = -1;
					break;
				}
				continue;
			}
		}
		break;
	}
	
	state = check();
	if(state >= 0)	return;
	if(cstep == step) {
		for(i=0;i<7;i++)
			record[i] = deck[i];
		record[7] = hand;
		cstep *= 2;
	}
}

void simulate2() {
	int now = deckk[ptrr].last+1;
	deckk[ptrr].last++;
	deckk[ptrr].s[now] = handd.s[handd.first];
	handd.first++;
	stepp++;
	
	int f,r,tmp,i;
	while(1) {
		if(deckk[ptrr].last-deckk[ptrr].first >= 3) {
			f = deckk[ptrr].first+1;
			r = deckk[ptrr].last;
			tmp = deckk[ptrr].s[f]+deckk[ptrr].s[f+1]+deckk[ptrr].s[r];
			if(tmp == 10 || tmp == 20 || tmp == 30) {
				handd.s[handd.last+1] = deckk[ptrr].s[f];
				handd.s[handd.last+2] = deckk[ptrr].s[f+1];
				handd.s[handd.last+3] = deckk[ptrr].s[r];
				handd.last += 3;
				
				deckk[ptrr].first += 2;
				deckk[ptrr].last--;
				if(deckk[ptrr].first >= deckk[ptrr].last) {
					deckk[ptrr].state = -1;
					break;
				}
				continue;
			}
			tmp = deckk[ptrr].s[f]+deckk[ptrr].s[r-1]+deckk[ptrr].s[r];
			if(tmp == 10 || tmp == 20 || tmp == 30) {
				handd.s[handd.last+1] = deckk[ptrr].s[f];
				handd.s[handd.last+2] = deckk[ptrr].s[r-1];
				handd.s[handd.last+3] = deckk[ptrr].s[r];
				handd.last += 3;
				
				deckk[ptrr].last -= 2;
				deckk[ptrr].first++;
				if(deckk[ptrr].first >= deckk[ptrr].last) {
					deckk[ptrr].state = -1;
					break;
				}
				continue;
			}
			tmp = deckk[ptrr].s[r-2]+deckk[ptrr].s[r-1]+deckk[ptrr].s[r];
			if(tmp == 10 || tmp == 20 || tmp == 30) {
				handd.s[handd.last+1] = deckk[ptrr].s[r-2];
				handd.s[handd.last+2] = deckk[ptrr].s[r-1];
				handd.s[handd.last+3] = deckk[ptrr].s[r];
				handd.last += 3;
				
				deckk[ptrr].last -= 3;
				if(deckk[ptrr].first >= deckk[ptrr].last) {
					deckk[ptrr].state = -1;
					break;
				}
				continue;
			}
		}
		break;
	}
}

void simulate3() {
	int now = deckkk[ptrrr].last+1;
	deckkk[ptrrr].last++;
	deckkk[ptrrr].s[now] = handdd.s[handdd.first];
	handdd.first++;
	steppp++;
	
	int f,r,tmp,i;
	while(1) {
		if(deckkk[ptrrr].last-deckkk[ptrrr].first >= 3) {
			f = deckkk[ptrrr].first+1;
			r = deckkk[ptrrr].last;
			tmp = deckkk[ptrrr].s[f]+deckkk[ptrrr].s[f+1]+deckkk[ptrrr].s[r];
			if(tmp == 10 || tmp == 20 || tmp == 30) {
				handdd.s[handdd.last+1] = deckkk[ptrrr].s[f];
				handdd.s[handdd.last+2] = deckkk[ptrrr].s[f+1];
				handdd.s[handdd.last+3] = deckkk[ptrrr].s[r];	
				handdd.last += 3;
				
				deckkk[ptrrr].first += 2;
				deckkk[ptrrr].last--;
				if(deckkk[ptrrr].first >= deckkk[ptrrr].last) {
					deckkk[ptrrr].state = -1;
					break;
				}
				continue;
			}
			tmp = deckkk[ptrrr].s[f]+deckkk[ptrrr].s[r-1]+deckkk[ptrrr].s[r];
			if(tmp == 10 || tmp == 20 || tmp == 30) {
				handdd.s[handdd.last+1] = deckkk[ptrrr].s[f];
				handdd.s[handdd.last+2] = deckkk[ptrrr].s[r-1];
				handdd.s[handdd.last+3] = deckkk[ptrrr].s[r];
				handdd.last += 3;
				
				deckkk[ptrrr].last -= 2;
				deckkk[ptrrr].first++;
				if(deckkk[ptrrr].first >= deckkk[ptrr].last) {
					deckkk[ptrrr].state = -1;
					break;
				}
				continue;
			}
			tmp = deckkk[ptrrr].s[r-2]+deckkk[ptrrr].s[r-1]+deckkk[ptrrr].s[r];
			if(tmp == 10 || tmp == 20 || tmp == 30) {
				handdd.s[handdd.last+1] = deckkk[ptrrr].s[r-2];
				handdd.s[handdd.last+2] = deckkk[ptrrr].s[r-1];
				handdd.s[handdd.last+3] = deckkk[ptrrr].s[r];
				handdd.last += 3;
				
				deckkk[ptrrr].last -= 3;
				if(deckkk[ptrrr].first >= deckkk[ptrrr].last) {
					deckkk[ptrrr].state = -1;
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
	while(scanf("%d",&hand.s[0]) && hand.s[0]) {
		for(i=1;i<52;i++)
			scanf("%d",&hand.s[i]);
		
		for(i=0;i<52;i++)
			handd.s[i] = handdd.s[i] = hand.s[i];
		hand.first = handd.first = handdd.first = 0;
		hand.last = handd.last = handdd.last = 51;
		
		for(i=0;i<7;i++) {
			deck[i].state = deck[i].first = deck[i].last = 0;
			deckk[i].state = deckk[i].first = deckk[i].last = 0;
			deckkk[i].state = deckkk[i].first = deckkk[i].last = 0;
			record[i] = deck[i];
		}
		record[7] = hand;
		
		state = -1;
		cstep = 1;
		step = stepp = steppp = 0;
		ptr = ptrr = ptrrr = 0;
		while(1) {
			simulate();
			if(state >= 0)	break;
			ptr++;
			if(ptr == 7)	ptr = 0;
			while(deck[ptr].state < 0) {
				ptr++;
				if(ptr == 7)	ptr = 0;
			}
		}
		
		if(state == 0)
			printf("Loss: %d\n",step+1);
		else if(state == 1)
			printf("Win : %d\n",step);
		else {
			int period = step-cstep/2;
			for(i=0;i<period;i++) {
				simulate3();
				ptrrr++;
				if(ptrrr == 7)	ptrrr = 0;
				while(deckkk[ptrrr].state < 0) {
					ptrrr++;
					if(ptrrr == 7)	ptrrr = 0;
				}
			}
			state = 0;
			while(steppp <= step) {
				simulate2();
				simulate3();
				statee = check2();
				if(statee)	break;
				ptrr++;
				if(ptrr == 7)	ptrr = 0;
				while(deckk[ptrr].state < 0) {
					ptrr++;
					if(ptrr == 7)	ptrr = 0;
				}
				ptrrr++;
				if(ptrrr == 7)	ptrrr = 0;
				while(deckkk[ptrrr].state < 0) {
					ptrrr++;
					if(ptrrr == 7)	ptrrr = 0;
				}
			}
			printf("Draw: %d\n",steppp);
		}
	}
	return 0;
}
