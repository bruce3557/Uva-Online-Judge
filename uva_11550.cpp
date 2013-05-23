#include <stdio.h>
struct node{
	int x,y;
}e[110];
int n,m,count;
char s[10][100];
int main(){
	int t,i,j,flag,a[10];
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		flag = 0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&s[i][j]);
		for(i=0;i<m;i++){
			count = 0;
			for(j=0;j<n;j++)
				if( s[j][i] )
					a[count++] = j;
			if(count!=2){
				flag = 1;
				break;
			} else {
				e[i] = (node){a[0],a[1]};
				e[i+m]=(node){a[1],a[0]};
			}
		}

		for(i=0;i<2*m;i++){
			for(j=0;j<2*m;j++)
				if(i != j && (e[i].x==e[j].x) && (e[i].y==e[j].y)){
					flag = 1;
					break;
				}
			if(flag)	break;
		}
		if(flag)	puts("No");
		else		puts("Yes");
	}
	return 0;
}
