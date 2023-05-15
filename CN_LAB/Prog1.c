#include<stdio.h>

int count(int num){
    int c=0;
    while(num>0){
        c++;
        num=num & (num-1);
    }
    return c;
}
int main(){
    int n;
    printf("Enter the number-->");
    scanf("%d",&n);
    int set=count(n);
    if(set==1){
        printf("%d is power of 2",n);
    }
    else{
        printf("%d is not power of 2",n);
    }
}