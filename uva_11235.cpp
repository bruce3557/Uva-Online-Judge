#include <stdio.h>
#include <string.h>

int Max(int a,int b) {
	return a>b?a:b;
}

int n,seq[100010];
struct node {
	int cnt;
	int lb,rb;

	node *lc, *rc;
	node() {
		cnt = 0;
		lc = rc = NULL;
	}
	node(int left, int right, int count) {
		lb = left; rb = right; cnt = count;
		lc = rc = NULL;
	}
};

node *Build(int left, int right) {
	if(left == right) {
		node *n_node = new node(left,right,1);
		return n_node;
	}
	
	int mid = (left+right)/2;
	node *n_node = new node();
	n_node->lb = left;
	n_node->rb = right;
	n_node->lc = Build(left, mid);
	n_node->rc = Build(mid+1, right);
	
	int cntt=0;
	for(int i=mid;i>=left && seq[i] == seq[mid];--i,++cntt);
	for(int i=mid+1;i<=right && seq[i] == seq[mid];++i,++cntt);
	
	n_node->cnt = Max(cntt, Max(n_node->lc->cnt,n_node->rc->cnt));
	
	return n_node;
}

int Query(node *ptr, int left, int right) {
	if((ptr->lb == left) && (ptr->rb == right))
		return ptr->cnt;
	int mid = (ptr->lb+ptr->rb)/2;
	if(right <= mid) {
		return Query(ptr->lc,left,right);
	} else if(left > mid) {
		return Query(ptr->rc,left,right);
	} else {
		int cntt=0;
		for(int i=mid;i>=left && seq[i] == seq[mid];--i,++cntt);
		for(int i=mid+1;i<=right && seq[i] == seq[mid];++i,++cntt);
		return Max(cntt,Max(Query(ptr->lc,left,mid),Query(ptr->rc,mid+1,right)));
	}
}

void Crash(node *ptr) {
	if(ptr == NULL)	return;
	Crash(ptr->lc);
	Crash(ptr->rc);
	delete ptr;
}

int main() {
	int Q;
	
	while(scanf("%d",&n) && n) {
		scanf("%d",&Q);
		for(int i=1;i<=n;++i)
			scanf("%d",seq+i);
		
		node *root;
		root = Build(1,n);
		while(Q--) {
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",Query(root, a, b));
		}
		
		Crash(root);
	}

	return 0;
}
