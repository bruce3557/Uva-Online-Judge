#include <stdio.h>
#include <string.h>

struct node {
	int s[5010],len;
	char sign;
	
	node() {
		len = 0;
		memset(s,0,sizeof(s));
	}
	void tran(int num) {
		len = 0;
		while(num) {
			s[len++] = num%10;
			num /= 10;
		}
	}

	bool operator <= (node t) const {
		if(len < t.len)
			return 1;
		else if(len > t.len )
			return 0;
		else {
			for(int i=len-1;i>=0;i--) {
				if(s[i] < t.s[i])
					return 1;
				else if(s[i] > t.s[i])
					return 0;
			}
			return 1;
		}
	}
	node operator - (node t) {
		node tmp;
		int i;
			for(i=0;i<len;i++) 
				tmp.s[i] = s[i]-t.s[i];
			
			for(i=0;i<len;i++)
				if(tmp.s[i] < 0) {
					tmp.s[i+1]--;
					tmp.s[i] += 10;
				}
			for(i=len-1;i>=0 && tmp.s[i] == 0;i--);
			if(i < 0)	tmp.len = 1;
			else		tmp.len = i+1;
			return tmp;
	}
	node operator * (node t) {
		int i,j;
		node tmp;
		for(i=0;i<len;i++)
			for(j=0;j<t.len;j++)
				tmp.s[i+j] += s[i]*t.s[j];
		for(i=0;i<len+t.len+5;i++)
			if(tmp.s[i] >= 10) {
				tmp.s[i+1] += tmp.s[i]/10;
				tmp.s[i] %= 10;
			}
		for(i=len+t.len+5;i>=0 && tmp.s[i] == 0;i--);
		if(i < 0)	tmp.len = 1;
		else		tmp.len = i+1;
		return tmp;
	}
	node operator / (int t) {
        node tmp;
		int tt = 0,i;
		for(i=len-1;i>=0;i--) {
			tt = tt*10 + s[i];
			tmp.s[i] = tt/t;
			tt %= t;
		}
		for(i=len-1;i>=0 && tmp.s[i] == 0;i--);
		if(i < 0)	tmp.len = 1;
		else		tmp.len = i+1;
		return tmp;
    }
	void print() {
		for(int i=len-1;i>=0;i--)
			printf("%d",s[i]);
		puts("");
	}
}catalan[1010];

int main() {
	
	int n;
	node c,d,tmp;
	catalan[1].tran(1);
	for(int i=2;i<=1000;i++) {
		d.tran(4*i-2);
		catalan[i] = catalan[i-1]*d/(i+1);
	}
	while(scanf("%d",&n) != EOF)
		catalan[n].print();
	return 0;
}
