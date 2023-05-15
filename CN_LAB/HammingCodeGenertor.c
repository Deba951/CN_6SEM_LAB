#include <stdio.h>
#include <math.h>
#include <string.h>
int code[32];  // Store hamming code

// Function to calculate bit for ith position
int ham_calc(int position, int newLen)
{
    int count = 0, i = position - 1, j;

    while (i < newLen)
    {
        for (j = i; j < i + position; j++)
        {
            if (code[j] == 1)
                count++;
        }
        i = i + 2 * position;
    }
    // if count is odd then add 1 as Parity Bit else add 0 as Parity Bit
    if (count % 2 == 0)
        return 0;
    else
        return 1;
}
// Function to solve Hamming Code
void solve(int input[], int n)
{
    int j = 0, k = 0, p = 0, newLen;
    // Find the number of parity bits required
    while ((int)pow(2,p) < (n+p+1))
    {
        p++;
    }
    newLen = p + n;

    for (int i = 0; i < newLen; i++)
    {
        // add 0 at the Hamming Code position
        if (i == ((int)pow(2, k) - 1))
        {
            code[i] = 0;
            k++;
        }
        // add Databits to other position
        else
        {
            code[i] = input[j];
            j++;
        }
    }
    for (int i = 0; i < p; i++)
    {
        int position = (int)pow(2, i);
        int value = ham_calc(position, newLen);
        code[position - 1] = value;
    }

    // Print the Hamming Code
    printf("\nThe generated Code Word is: ");
    for (int i = newLen-1; i >= 0; i--)
    {
        printf("%d", code[i]);
    }
}
int main()
{
    char dataword[1000];
    printf("Enter the Dataword-->");
    gets(dataword);
    int n = strlen(dataword);
    int input[n];
    for(int i=0;i<n;i++){
        if(dataword[i]=='1'){
            input[i]=1;
        }
        else{
            input[i]=0;
        }
    }
    solve(input, n);
    return 0;
}