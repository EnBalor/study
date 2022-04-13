#include <stdio.h>
#include <stdlib.h>
#define Swap(type, x, y)do{ type t = x; x = y; y = t; }while(0)

void Selection(int arr[], int arr_len)
{
	for (int i = 0; i < arr_len - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < arr_len; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		Swap(int, arr[i], arr[min]);

	}
}


int main(void)
{
	int arr_len;

	puts("배열의 길이를 입력");
	scanf_s("%d", &arr_len);

	int* arr = (int*)calloc(arr_len, sizeof(int));

	for (int i = 0; i < arr_len; i++)
	{
		printf("arr[%d] = ", i);
		scanf_s("%d", &arr[i]);
	}
	
	Selection(arr, arr_len);

	puts("오름차 정렬");
	for (int i = 0; i < arr_len; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	free(arr);

	return 0;
}