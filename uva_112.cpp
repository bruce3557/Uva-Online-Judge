#include <stdio.h>
#include <string.h>

int target;
struct node {
	int key;
	node *left,*right;
	
	node () {
		left = right = NULL;
	}
};

node *Build() {
	int num=0;
	char c;
	bool nega = false;
	
	while((c = getchar()) && (c == ' ' || c == '\n'));
	if(c == '(')
	while((c = getchar()) && (c == ' ' || c == '\n'));
	if(c == ')')	return NULL;
	else if(c >= '0' && c <= '9')	num = c-'0';
	else if(c == '-')	nega = true;
	
	while((c = getchar()) && c != '(') {
		if(c < '0' || c > '9')	continue;
		num = num*10+c-'0';
	}
	
	node *ptr = new node();
	ptr->key = num*(nega ? (-1) : 1);
	ptr->left = Build();
	ptr->right = Build();
	
	while((c = getchar()) && c != ')');
	return ptr;
}

void Erase(node *ptr) {
	if(ptr == NULL)	return;
	Erase(ptr->left);
	Erase(ptr->right);
	delete ptr;
}

bool Traverse(node *ptr,int sum) {
	if(ptr->left == NULL && ptr->right == NULL)	return (sum+ptr->key == target);
	if(ptr->left != NULL && Traverse(ptr->left,sum+ptr->key))	return true;
	if(ptr->right != NULL && Traverse(ptr->right,sum+ptr->key))	return true;
	return false;
}

int main() {

	while(scanf("%d",&target) != EOF) {
		node *root;
		root = Build();
		
		bool op;
		if(root == NULL)	op = false;
		else	 op = Traverse(root,0);
		
		if(op)	puts("yes");
		else	puts("no");
		
		Erase(root);
	}

	return 0;
}
