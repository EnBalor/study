#include <stdio.h>
#include <stdlib.h>

void insertion(int arr[], int arr_len)
{
	int i, j;

	for (i = 1; i < arr_len; i++)
	{
		int tmp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > tmp; j--)
		{
			arr[j] = arr[j - 1];
		}

		arr[j] = tmp;
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

	insertion(arr, arr_len);

	puts("오름차 정렬");
	for (int i = 0; i < arr_len; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	free(arr);

	return 0;
}