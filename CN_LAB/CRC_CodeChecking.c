#include<stdio.h>
#include<string.h>

int main(){
	char dataword[1000],divisor[1000],store[1000];
	printf("Enter the final codeword-->");
	gets(dataword);
	printf("Enter the divisor-->");
	gets(divisor);
	int count=strlen(divisor),n=strlen(dataword),c=0,p=0,flag=1;
	
	for(int i=0;i<(n+count-1);i++)
		store[c++]=dataword[i];
	
	for(int i=0;i<n;i++){
		
		if(dataword[i]=='0')
			continue;
		
		else{
			for(int j=i;j<(i+count);j++){
				if(dataword[j]==divisor[p++])
					dataword[j]='0';
				
				else
					dataword[j]=='1';
			}
		}
		p=0;
	}
	
	for(int i=n;i<(n+count-1);i++){
		if(dataword[i]=='1'){
            flag=0;
            break;
        }
	}
    
	if(flag==1){
        printf("\nNo error");
        printf("\nThe dataword is-->");
	    for(int i=0;i<(n-(count-1));i++)
		    printf("%c",store[i]);
    }

    else
        printf("\nError in data");
}