#include<stdio.h>
#include<string.h>

int map[101][101];
char s[101][101];

main(){
   int t,i,j,k,q,n,max;
   
   scanf("%d",&t);
   while(t--){
       scanf("%s",s[1]+1);
       n=strlen(s[1]+1);
	   
       for(i=2;i<=n;i++)
           scanf("%s",s[i]+1);
		   
       for(i=max=0;i<=n;i++)
           for(j=0;j<=n;j++)
               map[i][j] = 0;
			   
       for(i=1;i<=n;i++)
           for(j=1;j<=n;j++){
               map[i][j]=(s[i][j]-'0')?0:1;
               map[i][j] += map[i-1][j];
           }
		   
       for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
               map[i][j] += map[i][j-1];
			   
       for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
               for(k=0;k<i;k++)
                   for(q=0;q<j;q++)
                       if(map[i][j]+map[k][q] == map[i][q]+map[k][j])
                           max>?=(i-k)*(j-q);
						   
       printf("%d\n",max);
       if(t)   puts("");
   }
   
}
