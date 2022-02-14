#include <stdio.h>
#include <stdlib.h>

//동적할당
void main()
{
	//크기가 3인 배열
	int arr[3] = { 1, 2, 3 };

	// 동적 할당을 위한 포인터 변수 선언
	int *pArr;

	//int형 자료를 배열의 크기만큼 할당하기 위해 곱함
	//pArr = (int *)malloc(sizeof(int) * 3);

	//int형 자료 크기의 변수를 3개 할당
	pArr = (int *)calloc(3, sizeof(int));

	if (pArr == NULL)
	{
		printf("error");
	}

	//해당 반복문을 통해 메모리를 할당한다.
	for (int i = 0; i < 3; i++)
	{
		pArr[i] = arr[i];
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", pArr[i]);
	}
	// 할당된 공간 해제
	free(pArr);
}