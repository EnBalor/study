#include <stdio.h>
#include <stdlib.h>

//동적할당
void main()
{
	int arr[3];

	// 동적 할당을 위한 포인터 변수 선언
	int *pArr;

	//배열에 값 입력
	for (int i = 0; i < 3; i++)
	{
		arr[i] = i + 1;
	}

	//메모리 할당
	pArr = (int *)calloc(3, sizeof(int));

	for (int i = 0; i < 3; i++)
	{
		pArr[i] = arr[i];
		printf("%d\n", pArr[i]);
	}

	printf("\n");

	//할당된 메모리 재할당
	realloc(pArr, sizeof(int) * 5);

	for (int i = 0; i < 5; i++)
	{
		pArr[i] = arr[i];
		printf("%d\n", pArr[i]);
	}
	// 할당된 공간 해제
	free(pArr);
}