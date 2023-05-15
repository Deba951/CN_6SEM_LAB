#include<stdio.h>
int main(){
    int num,even=0,odd=0,n=0;
    int arr[1000];
    printf("Enter the number--> ");
    scanf("%d",&num);
    while(num>0){
        arr[n++]=num%2;
        num=num/2;
    }
    int rev[n+1];
    for(int i=0;i<n;i++){
        rev[i]=arr[n-i-1];
        even^=rev[i];
    }
    if(even==0){
        odd=1;
    }
    printf("Even Parity Bit-->%d\n",even);
    rev[n]=even;
    printf("Even Parity Codeword-->\n");
    for(int i=0;i<=n;i++){
        printf("%d",rev[i]);
    }
    printf("\nOdd Parity Bit-->%d\n",odd);
    rev[n]=odd;
    printf("Odd Parity Codeword-->\n");
    for(int i=0;i<=n;i++){
        printf("%d",rev[i]);
    }
}