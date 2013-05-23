#include <stdio.h>

char s[15],t[15],tmp;
int n;

void go(int now){
	if(now >= n){
		t[n] = '\0';
		puts(t);
		return;
	}
	t[n-1-now] = s[now];
	go(now+1);
	char tt[15];
	int i;
	for(i=n-1-now;i<n;i++)
		tt[i] = t[i];
	for(i=n-now;i<n;i++){
		tmp = t[i];
		t[i] = t[i-1];
		t[i-1] = tmp;
		go(now+1);
	}
	for(i=n-now-1;i<n;i++)
		t[i] = tt[i];
}

int main(){
	int c = 0,i;
	while(gets(s) != NULL){
		if(c)	puts("");
		else	c = 1;
		for(i=0;s[i] != '\0';i++);
		n = i;
		go(0);
	}
	return 0;
}
