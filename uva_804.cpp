#include <stdio.h>
#include <string.h>

int NP, NT;
int token[110];
int count[110];

int input[110][300], output[110][300];
int n_in[110], n_out[110];

int main() {
	int cases=0;
	
	while(scanf("%d",&NP) && NP) {
		for(int i=1;i<=NP;++i)
			scanf("%d",token+i);
			
		
		scanf("%d",&NT);
		for(int i=1;i<=NT;++i) {
			n_in[i] = 0;
			n_out[i] = 0;
			int num;
			while(scanf("%d",&num) && num) {
				if(num < 0) {
					int link = -num;
					input[i][n_in[i]++] = link;
				} else {
					int link = num;
					output[i][n_out[i]++] = link;
				}
			}
		}
		
		int simu, round;
		bool dead=false;
		scanf("%d",&simu);
		for(round=0;round < simu;++round) {
			int ptr = -1;
			for(int i=1;i<=NT;++i) {
				memset(count, 0, sizeof(count));
				for(int j=0;j<n_in[i];++j)
					++count[input[i][j]];
				bool ok=true;
				for(int j=1;j<=NP;++j)
					if(token[j] < count[j]) {
						ok = false;
						break;
					}
				if(ok) {
					ptr = i;
					break;
				}
			}
			
			if(ptr == -1) {
				dead = true;
				break;
			} else {
				for(int i=0;i<n_in[ptr];++i)
					--token[input[ptr][i]];
				for(int i=0;i<n_out[ptr];++i)
					++token[output[ptr][i]];
			}
		}
		
		printf("Case %d:", ++cases);
		if(dead) {
			printf(" dead after %d transitions\n", round);
		} else {
			printf(" still live after %d transitions\n", simu);
		}
		printf("Places with tokens:");
		for(int i=1;i<=NP;++i) 
			if(token[i] > 0)
				printf(" %d (%d)", i, token[i]);
		puts("");
				
		puts("");
	}
	
	return 0;
}
