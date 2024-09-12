#include<stdio.h>
#include<math.h>

void binary(int *n){
    int rem,bin=0,place=1;
    while(*n >0){
        rem=*n%2;
        bin=bin+(rem*place);
        place=place*10;
        *n=(*n)/2;
    }
    *n=bin;
    
}
int bintodec(int n){
    int rem,bin=0,place=1;
    while(n >0){
        rem=n%10;
        bin=bin+(rem*place);
        place=place*2;
        n=(n)/10;
    }
    return bin;
    
}
void andop(int n,int m){
    int p=n&m;
   printf("%d & %d = %d \n",n , m,bintodec(p));
}
void orop(int n,int m){
    int p=n|m;
   printf("%d | %d = %d\n",n,m,bintodec(p));
}
void xorop(int n,int m){
    int p=n^m;
   printf("%d ^ %d = %d\n",n , m,bintodec(p));
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    binary(&n);
    binary(&m);
    printf("%d\n",n);
    printf("%d\n",m);
    andop(n,m);
    orop(n,m);
    xorop(n,m);
    return 0;
}