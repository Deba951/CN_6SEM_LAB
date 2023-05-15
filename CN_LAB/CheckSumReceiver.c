#include <stdio.h>
#include <string.h>
int isPower(int n){
    int c = 0;
    
    while (n != 0){
        n = (n & (n - 1));
        c++;
    }
    
    if (c == 1)
        return 1;
    
    return 0;
}


int main(){
    char dataword[1000], store[1000];
    int sl, newlen, l = 0;

    printf("Enter the Dataword-->");
    gets(dataword);
    int len = strlen(dataword);
    
    do{
        printf("Enter the segment length-->");
        scanf("%d", &sl);
    } while (isPower(sl) == 0);

    int sum[100];
    
    for (int i = 0; i < sl; i++)
        sum[i] = 0;
    
    if (len % sl != 0){
        int i, diff = (sl - (len % sl));
        
        for (int i = 0; i < diff; i++)
            store[i] = '0';
        
        store[i] = '\0';
        l = strlen(store);
        strcat(store, dataword);
        strcpy(dataword, store);
        newlen = strlen(store);
    }
    
    newlen = len;
    printf("Dataword after padding-->");
    
    for (int i = 0; i < newlen; i++)
        printf("%c", dataword[i]);
    
    for (int i = 0; i < newlen; i += sl){
        int c = 0, p = sl - 1;

        for (int j = (sl + i - 1); j >= i; j--){
            int s = sum[p];
            sum[p] = ((dataword[j] - '0') + sum[p] + c) % 2;
            c = (c + (dataword[j] - '0') + s) / 2;
            p--;
        }
        
        if (c == 1){

            for (int k = sl - 1; k >= 0; k--){
                int s = sum[k];
                sum[k] = (sum[k] + c) % 2;
                c = (c + s) / 2;
            }
        }
    }

    int flag = 0;
    printf("\nCheckSum Bits-->");
    
    for (int i = 0; i < sl; i++){
        if (sum[i] == 0){
            printf("%d", 1);
            sum[i] = 1;
        }

        else{
            printf("%d", 0);
            sum[i] = 0;
        }
    }
    
    for (int i = 0; i < sl; i++){
        if (sum[i] == 1){
            flag = 1;
            break;
        }
    }

    if (flag == 1)
        printf("\nError in Data!!");
    
    else
        printf("\nNo error in data");
    
    return 0;
}