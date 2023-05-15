#include<stdio.h>
#include<string.h>
int main(){
    char arr[1000];
    printf("Enter the binary string--> ");
    gets(arr);
    int n=strlen(arr),count1=0,count2=0,count4=0;
    for(int i=0;i<n;i+=2){
        if(arr[i]=='1'){
            count1++;
        }
    }
    for(int i=1;i<n;i+=4){
        for(int j=i;j<=i+1;j++){
            if(arr[j]=='1'){
                count2++;
            }
        }
    }
    for(int i=3;i<n;i+=8){
        for(int j=i;j<=i+3;j++){
            if(arr[j]=='1'){
                count4++;
            }
        }
    }
    printf("Number of 1 at alternate one position-->%d\n",count1);
    printf("Number of 1 at alternate two position-->%d\n",count2);
    printf("Number of 1 at alternate four position-->%d\n",count4);
}