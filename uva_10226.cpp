#include<stdio.h>
#include<string.h>
int sum;
char s[1001],past[1001];
struct node{
   int len;
   node *child[128];
};
void insert(node *ptr,int nowlen){
   if(nowlen==strlen(s)){
       ptr->len++;
       sum++;
       return;
   }
   if(ptr->child[s[nowlen]]==NULL){
       node *tmp=new node;
       tmp->len=0;
       for(int i=0;i<257;i++)
           tmp->child[i]=NULL;
       ptr->child[s[nowlen]]=tmp;
   }
   insert(ptr->child[s[nowlen]],nowlen+1);
}
void go(node *ptr,int nowlen){
   int i;
   if(ptr->len>0){
       for(i=0;i<nowlen;i++)
           printf("%c",past[i]);
       printf(" %.4lf\n",(double)ptr->len/sum*100);
   }
   for(i=0;i<257;i++)
       if(ptr->child[i]!=NULL){
           past[nowlen]=i;
           go(ptr->child[i],nowlen+1);
       }
}
int main(){
   int t,i,c=0;
   node *root=new node;
   scanf("%d%c",&t,&s[0]);
   gets(s);
   while(t--){
       if(c)   puts("");
       else    c=1;
       sum=root->len=0;
       for(i=0;i<257;i++)
           root->child[i]=NULL;
       while(gets(s)!=NULL && s[0]!='\0')
           insert(root,0);
       go(root,0);
	}
	return 0;
}
