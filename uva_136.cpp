
#include<stdio.h>
main(){
    long long i,j,k,p,ptr,ugn[1501],min;
    ugn[0]=1,p=1;
    while(p<1501){
        min = 2147483647;
        for(ptr=0;ptr<p;ptr++){
            i=2*ugn[ptr],j=3*ugn[ptr],k=5*ugn[ptr];
            if(i>ugn[p-1] && i<min)
                min = i;
            else if(j>ugn[p-1] && j<min)
                min = j;
            else if(k>ugn[p-1] && k<min)
                min = k;
        }
        ugn[p++] = min;
    }
    printf("The 1500'th ugly number is %lld.\n",ugn[1499]);
}
