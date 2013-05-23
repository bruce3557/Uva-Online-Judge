#include <stdio.h>
#include <string.h>

char s1[10010],s2[10010];

int main(){
	int n,i,j,tmp;
	int equal,dis,ainb,bina;
	char c=0;
	while(scanf("%d%c",&tmp,&c) != EOF){
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		s1[tmp] = 1;
		while(c != '\n'){
			scanf("%d%c",&tmp,&c);
			s1[tmp] = 1;
		}
		c = 0;
		while(c != '\n'){
			scanf("%d%c",&tmp,&c);
			s2[tmp] = 1;
		}
		equal = dis = ainb = bina = 1;
		for(i=0;i<10010;i++){
			if(s1[i] == 1){
				if(s2[i] == 1){
					dis = 0;
				} else {
					ainb = equal = 0;
				}
			} else if(s2[i] == 1){
				bina = equal = 0;
			}
		}
		if(equal){
			puts("A equals B");
		} else if(ainb){
			puts("A is a proper subset of B");
		} else if(bina){
			puts("B is a proper subset of A");
		} else if(dis){
			puts("A and B are disjoint");
		} else {
			puts("I'm confused!");
		}
	}
	return 0;
}
