#include<stdio.h>
#include<string.h>
int main(){
    char arr[1000];
    char c;
    printf("Enter the codeword--> ");
    gets(arr);
    printf("Enter the Parity Scheme (e for even and o for odd)-->");
    scanf("%c",&c);
    int n=strlen(arr),count=0;
    for(int i=0;i<n;i++){
        if(arr[i]=='1'){
            count++;
        }
    }
    if(c=='e'){
        if(count%2==0){
            printf("No error\n");
            printf("DataWord is-->\n");
            for(int i=0;i<n-1;i++){
                printf("%c",arr[i]);
            }
        }
        else{
            printf("Error in Data!!!");
        }
    }
    else{
        if(count%2!=0){
            printf("No error\n");
            printf("DataWord is-->\n");
            for(int i=0;i<n-1;i++){
                printf("%c",arr[i]);
            }
        }
        else{
            printf("Error in Data!!!");
        }
    }
}