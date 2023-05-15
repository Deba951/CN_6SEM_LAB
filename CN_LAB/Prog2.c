#include<stdio.h>
#include<string.h>
int main(){
    char arr[1000];
    int store[26];
    for(int i=0;i<26;i++){
        store[i]=0;
    }
    printf("Enter the alphabet string--> ");
    gets(arr);
    int n=strlen(arr);
    for(int i=0;i<n;i++){
        if((arr[i]-'a')==32){
            continue;
        }
        store[arr[i]-'a']++;
    }
    for(int i=0;i<n;i++){
        if((arr[i])==32){
            continue;
        }
        printf("%c=%d\n",arr[i],store[arr[i]-'a']);
    }
}