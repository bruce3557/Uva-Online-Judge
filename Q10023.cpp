#include <stdio.h>
#include <string.h>

struct node {
	int s[1010],len;
	
	node() {
		memset(s,0,sizeof(s));
		len = 0;
	}
	
	void trans(char *ss,int slen) {
		len = slen;
		for(int i=0;i<slen;i++)
			s[i] = ss[slen-1-i]-'0';
	}
	
	node operator + (int t) {
		int i;
		node tmp;
		
		tmp.s[0] = s[0]+t;
		for(i=1;i<len;i++)
			tmp.s[i] = s[i];
			
		for(i=0;i<len;i++)
			if(tmp.s[i] >= 10) {
				tmp.s[i+1] += tmp.s[i]/10;
				tmp.s[i] %= 10;
			}
			
		for(i=len+9;i>=0 && tmp.s[i] == 0;i--);
		if(i < 0)	tmp.len = 1;
		else		tmp.len = i+1;
		
		return tmp;
	}
	
	node operator * (int t) {
		int i;
		node tmp;
		for(i=0;i<len;i++)
			tmp.s[i] = s[i]*t;
			
		for(i=0;i<len+10;i++)
			if(tmp.s[i] >= 10) {
				tmp.s[i+1] += tmp.s[i]/10;
				tmp.s[i] %= 10;
			}
			
		for(i=len+9;i>=0 && tmp.s[i] == 0;i--);
		if(i < 0)	tmp.len = 1;
		else		tmp.len = i+1;
		
		return tmp;
	}
	
	node sqrt() {
		node Q,tmp,tmp2,tmp3;
		tmp = (*this);
		int i,tt,j,k,q,x;
		char flag;
				
		if(len & 1) {
			Q.len = len/2+1;
			i = Q.len-1;
			j = len-1;
			tmp3.len = 1;
			
			while(i >= 0 && j >= 0) {
				
				for(k=0;k<=9;k++) {
					flag = 0;
					tmp3.s[0] = k;
					tmp2 = tmp3*k;
					if(tmp2.len > tmp.len-j) {
						flag = 2;
						break;
					} else if(tmp2.len < tmp.len-j) {
						continue;
					} else {
						for(x=tmp2.len-1;x>=0;x--) {
							if(tmp.s[x+j] > tmp2.s[x]) {
								flag = 1;
								break;
							} else if(tmp.s[x+j] < tmp2.s[x]) {
								flag = 2;
								break;
							}
						}
							
						if(flag == 2)	break;
					}
				}
				
				if(tmp3.s[0] && flag == 2)
					tmp3.s[0]--;
				Q.s[i] = tmp3.s[0];
				
				tmp2 = tmp3*Q.s[i];
				tmp3 = tmp3+Q.s[i];
				
				
				for(x=j;x<tmp.len;x++) {
					tmp.s[x] -= tmp2.s[x-j];
					if(tmp.s[x] < 0) {
						tmp.s[x+1]--;
						tmp.s[x] += 10;
					}
				}
				
				for(x=tmp.len;x>0 && tmp.s[x-1] == 0;x--);
				tmp.len = x;
				
				tmp3 = tmp3*10;
				
				i--, j-=2;
			}
			
			return Q;
		} else {
			Q.len = len/2;
			i = Q.len-1;
			j = len-2;
			tmp3.len = 1;
			
			while(i >= 0 && j >= 0) {
				
				for(k=0;k<=9;k++) {
					flag = 0;
					tmp3.s[0] = k;
					tmp2 = tmp3*k;
					if(tmp2.len > tmp.len-j) {
						flag = 2;
						break;
					} else if(tmp2.len < tmp.len-j) {
						continue;
					} else {
						for(x=tmp2.len-1;x>=0;x--) {
							if(tmp.s[x+j] > tmp2.s[x]) {
								flag = 1;
								break;
							} else if(tmp.s[x+j] < tmp2.s[x]) {
								flag = 2;
								break;
							}
						}
							
						if(flag == 2)	break;
					}
				}
				
				if(tmp3.s[0] && flag == 2)
					tmp3.s[0]--;
				Q.s[i] = tmp3.s[0];
				
				tmp2 = tmp3*Q.s[i];
				tmp3 = tmp3+Q.s[i];
				
				for(x=j;x<tmp.len;x++) {
					tmp.s[x] -= tmp2.s[x-j];
					if(tmp.s[x] < 0) {
						tmp.s[x+1]--;
						tmp.s[x] += 10;
					}
				}
				
				for(x=tmp.len;x>0 && tmp.s[x-1] == 0;x--);
				tmp.len = x;
				
				tmp3 = tmp3*10;

				i--, j-=2;
			}
			
			return Q;
		}
	}
	
	void print() {
		for(int i=len-1;i>=0;i--)
			printf("%d",s[i]);
		puts("");
	}
};

int main() {
	
	int i,j,n,t,c=0;
	char s[1010];
	node compute,ans;

	scanf("%d%*c",&t);
	while(t--) {
		if(c)	puts("");
		else	c = 1;
		scanf("%s",s);
		n = strlen(s);
		compute.trans(s,n);
		ans = compute.sqrt();
		ans.print();
	}
	
	return 0;
}
