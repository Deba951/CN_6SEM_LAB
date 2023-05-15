#include <stdio.h>
#include <string.h>
#include <math.h>

int p=0;
int hamming_decode(int input[], int n)
{
	while ((int)pow(2, p) < (n + p + 1))
	{
		p++;
	}
	int parity[p];
	memset(parity, 0, sizeof(parity));
	int pos = 0;
	for (int i = 0; i < p; i++)
	{
		int count = 0;
		for (int j = pow(2, i) - 1; j < n; j = j + pow(2, i + 1))
		{
			for (int k = 0; k < pow(2, i); k++)
			{
				if (j + k >= n)
					break;
				count += input[j + k];
			}
		}
		parity[i] = count % 2;
		pos += parity[i] * pow(2, i);
	}
	if (pos == 0)
		return 0;
	else
		return pos - 1;
}
void correct_error(int input[], int n, int error_pos)
{
	int parity[p];
	memset(parity, 0, sizeof(parity));
	int pos = 0;
	for (int i = 0; i < p; i++)
	{
		int count = 0;
		for (int j = pow(2, i) - 1; j < n; j = j + pow(2, i + 1))
		{
			for (int k = 0; k < pow(2, i); k++)
			{
				if (j + k >= n)
					break;
				count += input[j + k];
			}
		}
		parity[i] = count % 2;
		pos += parity[i] * pow(2, i);
	}
	if (pos == 0)
		printf("No error detected.\n");
	else
	{
		printf("Error detected at bit position %d.\n", n - (pos - 1));
		input[pos - 1] = input[pos - 1] == 0 ? 1 : 0;
		printf("Corrected code: ");
		for (int i = 0; i < n; i++)
		{
			if (i == pos - 1)
				printf("%d", input[i]);
			else
				printf("%d", input[i]);
		}
		printf("\n");
	}
}
int main()
{
	char dataword[1000];
	printf("Enter the dataword-->");
	gets(dataword);
	int n = strlen(dataword);
	int input[n];
	for (int i = 0; i < n; i++)
	{
		if (dataword[i] == '1')
			input[i] = 1;
		else
			input[i] = 0;
	}
	int error_pos = hamming_decode(input, n);
	if (error_pos == -1)
		printf("Invalid code length.\n");
	else if (error_pos == 0)
		correct_error(input, n, 0);
	else
		correct_error(input, n, error_pos);
	return 0;
}