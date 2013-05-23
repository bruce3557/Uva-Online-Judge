#include <stdio.h>
#include <string.h>
#include <math.h>

int N, Q;
int n;
int A[100010];
int pos[100010];

struct node {
  int begin, end, value;

  void set(int _begin, int _end, int _value) {
    begin = _begin; end = _end; value = _value;
  }

  int count() {
    return end - begin + 1;
  }
} array[100010];

int ST[1000010][20];

void ConstructRMQ(int *A, int N) {
  n = 0;
  int start = 0;
  int end = 1;
  A[N] = -1000000000;
  pos[0] = 0;
  for(;end <= N;++end) {
    if(A[end-1] != A[end]) {
      array[n++].set(start, end-1, A[end-1]);
      pos[end] = n;
      start = end;
    } else {
      pos[end] = n;
    }
  }

  // Start construct RMQ
  for(int i=0;i<n;++i)
    ST[i][0] = i;
  for(int i=1;(1<<i)<=n;++i)
    for(int j=0;j+(1<<i)<=n;++j)
      ST[j][i] = (array[ST[j][i-1]].count() > array[ST[j+(1<<(i-1))][i-1]].count() ) ? ST[j][i-1] : ST[j+(1<<(i-1))][i-1];
}

int getIndex(int x) {
  return pos[x];
}

int RMQ(int a, int b) {
  int loca = getIndex(a);
  int locb = getIndex(b);
  if(loca == locb)  return (b - a + 1);
  
  int x = array[loca].end - a + 1;
  int y = b - array[locb].begin + 1;
  int res = (x > y) ? x : y;
  if(loca + 1 == locb)
    return res;
  
  int pa = loca + 1;
  int pb = locb - 1;

  int z = (int)ceil(log2((pb-pa+1)/2.0));
  if(z < 0) z = 0;
  int ca = array[ST[pa][z]].count();
  int cb = array[ST[pb-(1<<z)+1][z]].count();
  int g = (ca > cb) ? ca : cb;
  return (g > res) ? g : res;
}

int main() {

  while(scanf("%d",&N) && N) {
    scanf("%d",&Q);
    for(int i=0;i<N;++i)
      scanf("%d", A+i);

    ConstructRMQ(A, N);
 
    while( Q-- ) {
      int a, b;
      scanf("%d%d", &a, &b);
      printf("%d\n", RMQ(a-1, b-1) );
    }
  }

  return 0;
}

