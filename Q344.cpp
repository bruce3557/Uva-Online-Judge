#include <stdio.h>

int cnt[110][5];
int ans[5];                    /*0->i, 1->v, 2->x, 3->l, 4->c*/

int main(){
	int n,i,j;
	for(i=0;i<100;i++){
		j = i%10;
		if(j == 1) {
			cnt[i][0]++;
		} else if(j == 2) {
			cnt[i][0] +=2;
		} else if(j == 3) {
			cnt[i][0] +=3;
		} else if(j == 4) {
			cnt[i][0]++;
			cnt[i][1]++;
		} else if(j == 5) {
			cnt[i][1]++;
		} else if(j == 6) {
			cnt[i][0]++;
			cnt[i][1]++;
		} else if(j == 7) {
			cnt[i][0] += 2;
			cnt[i][1]++;
		} else if(j == 8) {
			cnt[i][0] += 3;
			cnt[i][1]++;
		} else if(j == 9) {
			cnt[i][0]++;
			cnt[i][2]++;
		}
		j = i/10;
		if(j == 1){
			cnt[i][2]++;
		} else if(j == 2) {
			cnt[i][2] += 2;
		} else if(j == 3) {
			cnt[i][2] += 3;
		} else if(j == 4) {
			cnt[i][2]++;
			cnt[i][3]++;
		} else if(j == 5) {
			cnt[i][3]++;
		} else if(j == 6) {
			cnt[i][2]++;
			cnt[i][3]++;
		} else if(j == 7) {
			cnt[i][2] += 2;
			cnt[i][3]++;
		} else if(j == 8) {
			cnt[i][2] += 3;
			cnt[i][3]++;
		} else if(j == 9) {
			cnt[i][2]++;
			cnt[i][4]++;
		}
	}
	cnt[100][0] = cnt[100][1] = cnt[100][2] = cnt[100][3] = 0, cnt[100][4] = 1;
	while(scanf("%d",&n) && n){
		for(i=0;i<5;i++)
			ans[i] = 0;
		for(i=1;i<=n;i++)
			for(j=0;j<5;j++)
				ans[j] += cnt[i][j];
		printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,ans[0],ans[1],ans[2],ans[3],ans[4]);
	}
	return 0;
}
