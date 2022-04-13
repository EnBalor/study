#include <stdio.h>
#include <stdlib.h>
#define Swap(type, x, y)do{ type t = x; x = y; y = t; }while(0)

void Bubble(int arr[], int arr_len)
{
	for (int i = 0; i < arr_len - 1; i++)
	{
		for (int j = arr_len - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				Swap(int, arr[j - 1], arr[j]);
			}
		}

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

	Bubble(arr, arr_len);

	puts("오름차 정렬");
	for (int i = 0; i < arr_len; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	free(arr);

	return 0;
}