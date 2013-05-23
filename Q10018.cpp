#include <stdio.h>
#include <string.h>

char s[1010],t[1010];
int n;

char check(){
	int i;
	for(i = n-1;i>=0;i--)
		if(s[i] != s[n-1-i])
			return 0;
	return 1;
}

int main(){
	int tt,i,j,cnt;
	scanf("%d",&tt);
	getchar();
	while(tt--){
		gets(s);
		for(i=0;s[i] != '\0';i++);
		n = i;
		for(i=0;i<n;i++)
			s[i] -= '0';
		cnt = 0;
		while(1){
			if(check())	break;
			memset(t,0,sizeof(char)*n+10);
			for(i=0;i<n;i++)
				t[i] = s[i]+s[n-1-i];
			for(i=0;i<n;i++)
				if(t[i] >= 10){
					t[i+1] += t[i]/10;
					t[i] %= 10;
				}
			for(i=n+5;t[i] == '\0';i--);
			n = i+1;
			for(i=0;i<n;i++)
				s[i] = t[i];
			cnt++;
		}
		for(i=0;i<n;i++)
			s[i] += '0';
		s[n] = '\0';
		printf("%d %s\n",cnt,s);
	}
	return 0;
}
