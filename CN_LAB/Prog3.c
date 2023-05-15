#include<stdio.h>
#include<string.h>
int main(){
    char arr[1000];
    printf("Enter the binary string--> ");
    gets(arr);
    int n=strlen(arr),count=0;
    for(int i=0;i<n;i++){
        if(arr[i]=='1'){
            count++;
        }
    }
    printf("Number of 1-->%d",count);
}