#include<stdio.h>
#include<string.h>

int main(){
	char dataword[1000],divisor[1000],store[1000];
	printf("Enter the dataword-->");
	gets(dataword);
	printf("Enter the divisor-->");
	gets(divisor);
	int count=strlen(divisor),n=strlen(dataword),c=0,p=0;
	
	for(int i=n;i<(n+count-1);i++)
		dataword[i]='0';
	
	for(int i=0;i<(n+count-1);i++)
		store[i]=dataword[i];
	
	for(int i=0;i<n;i++){
		if(dataword[i]=='1'){
			for(int j=i;j<(i+count);j++){
				if(dataword[j]==divisor[p++])
					dataword[j]='0';
				
				else
					dataword[j]='1';
			}
		}
		p=0;
	}
	
	for(int i=n;i<(n+count-1);i++)
		store[i]=dataword[i];
	
	printf("\nThe final codeword is-->");
	
	for(int i=0;i<(n+count-1);i++)
		printf("%c",store[i]);
	
	return 0;
}